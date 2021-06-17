//
//  main.cpp
//  1767. 프로세서 연결하기
//
//  Created by JaeHyeob on 29/02/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

// DFS, 재귀함수 사용

// 코드가 반복돼서 지저분하더라도 실행시간을 줄이는 습관
// 꼭 필요한 경우만 작성하고 아닌 경우는 포함 안 시키도록 작성할 것

#include <iostream>

using namespace std;

pair<int, int> core_list[12];
int core_size = 0;
int table[12][12];
int N = 0;

int cur_core = 0;
int cur_dist = 0;
int max_core = 0;
int min_dist = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void brush(int c){
    for(int w = 0; w < 4; w++){
        int x = core_list[c].first;
        int y = core_list[c].second;
        int TF = 1;
        int dist = 0;
        
        while(true){
            x = x+dx[w];
            y = y+dy[w];
            if(x == -1 || x == N || y == -1 || y == N){
                break;
            }
            if(table[x][y] == 1){
                TF = 0;
                break;
            }
        }
        
        if(TF == 1){
            x = core_list[c].first;
            y = core_list[c].second;
            while(true){
                x = x+dx[w];
                y = y+dy[w];
                if(x == -1 || x == N || y == -1 || y == N){
                    break;
                }
                table[x][y] = 1;
                dist++;
            }
            cur_core++;
            cur_dist += dist;
        }
        
        if(c == core_size-1){
            if(max_core < cur_core){
                max_core = cur_core;
                min_dist = cur_dist;
            }
            else if(max_core == cur_core && min_dist > cur_dist){
                min_dist = cur_dist;
            }
        }
        else{
            brush(c+1);
        }
        
        if(TF == 1){
            x = core_list[c].first;
            y = core_list[c].second;
            while(true){
                x = x+dx[w];
                y = y+dy[w];
                if(x == -1 || x == N || y == -1 || y == N){
                    break;
                }
                table[x][y] = 0;
            }
            cur_core--;
            cur_dist -= dist;
        }
    }
}

int main(){
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++){
        core_size = 0;
        cur_core = 0;
        cur_dist = 0;
        max_core = 0;
        min_dist = 0;
        
        cin >> N;
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> table[i][j];
                if(table[i][j] == 1){
                    if(i == 0 || i == N-1 || j == 0 || j == N-1){
                        continue;
                    }
                    else{
                        core_list[core_size] = {i, j};
                        core_size++;
                    }
                }
            }
        }
        
        brush(0);
        
        cout << "#" << t << " " << min_dist << endl;
    }
    
    return 0;
}

