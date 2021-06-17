//
//  main.cpp
//  2382. 미생물 격리
//
//  Created by JaeHyeob on 10/03/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//



// 12 34 변경은 홀수 짝수 이용
// if(temp.dir % 2) temp.dir = temp.dir-1;
// else temp.dir = temp.dir+1;

#include <iostream>
#include <vector>

using namespace std;

struct node{
    int count;
    int way;
};

vector<node> arr[100][100];
int size_arr[100][100];
int N, M, K;
int i_input, j_input, count_input, way_input;
int i_move[5] = {0, -1, 1, 0, 0};
int j_move[5] = {0, 0, 0, -1, 1};
int res;

void cal_size(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            size_arr[i][j] = arr[i][j].size();
        }
    }
}

void move(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < size_arr[i][j]; k++){
                int temp_way = arr[i][j][0].way;
                arr[i+i_move[temp_way]][j+j_move[temp_way]].push_back({arr[i][j][0].count, temp_way});
                arr[i][j].erase(arr[i][j].begin());
            }
        }
    }
}

void cal_sum(){
    for(int i = 1; i < N-1; i++){
        for(int j = 1; j < N-1; j++){
            if(size_arr[i][j] >= 2){
                int sum_count = arr[i][j][0].count;
                int temp_way = arr[i][j][0].way;
                int temp_count = arr[i][j][0].count;
                for(int k = 1; k < size_arr[i][j]; k++){
                    sum_count += arr[i][j][k].count;
                    if(temp_count < arr[i][j][k].count){
                        temp_count = arr[i][j][k].count;
                        temp_way = arr[i][j][k].way;
                    }
                }
                arr[i][j].clear();
                arr[i][j].push_back({sum_count, temp_way});
                size_arr[i][j] = 1;
            }
        }
    }
}

void cal_half(){
    for(int i = 0; i < N; i++){
        if(size_arr[i][0] != 0){
            arr[i][0][0].count = arr[i][0][0].count / 2;
            arr[i][0][0].way = 4;
            if(arr[i][0][0].count == 0){
                arr[i][0].clear();
                size_arr[i][0] = 0;
            }
        }
        if(size_arr[i][N-1] != 0){
            arr[i][N-1][0].count = arr[i][N-1][0].count / 2;
            arr[i][N-1][0].way = 3;
            if(arr[i][N-1][0].count == 0){
                arr[i][N-1].clear();
                size_arr[i][N-1] = 0;
            }
        }
        if(size_arr[0][i] != 0){
            arr[0][i][0].count = arr[0][i][0].count / 2;
            arr[0][i][0].way = 2;
            if(arr[0][i][0].count == 0){
                arr[0][i].clear();
                size_arr[0][i] = 0;
            }
        }
        if(size_arr[N-1][i] != 0){
            arr[N-1][i][0].count = arr[N-1][i][0].count / 2;
            arr[N-1][i][0].way = 1;
            if(arr[N-1][i][0].count == 0){
                arr[N-1][i].clear();
                size_arr[N-1][i] = 0;
            }
        }
    }
}

void cal_res(){
    res = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(size_arr[i][j] != 0){
                res += arr[i][j][0].count;
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++){
        cin >> N >> M >> K;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                arr[i][j].clear();
            }
        }
        for(int k = 0; k < K; k++){
            cin >> i_input >> j_input >> count_input >> way_input;
            arr[i_input][j_input].push_back(node{count_input, way_input}); // 상하좌우
        }
        
        cal_size();
        
        for(int m = 0; m < M; m++){
            move();
            cal_size();
            cal_sum();
            cal_half();
        }
        
        cal_res();
        
        cout << "#" << t << " " << res << endl;
    }
    
    return 0;
}
