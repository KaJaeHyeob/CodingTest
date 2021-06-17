//
//  main.cpp
//  2383. 점심 식사시간
//
//  Created by JaeHyeob on 06/03/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

// DFS, 재귀함수
// sort() 사용하는 비교 함수 만들기
// https://blockdmask.tistory.com/178

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

struct node{
    int n;
    int dist1;
    int dist2;
};

pair<int, int> people_xy_list[20];
pair<int, int> exit_xy_list[2];
int exit_dist[2];
node all_list[20];
vector<node> list1;
vector<node> list2;
vector<int> cal1;
vector<int> cal2;
int down[3];

int N;
int num;
int pn;
int en;
int res_min;
int temp_min1;
int temp_min2;
int cur_time;
int down_size;

void DFS(int, int);
void cal_min();

void DFS(int n, int fisrt_secnond){
    if(fisrt_secnond == 0){
        list1.push_back(all_list[n]);
        if(n == pn-1){
            cal_min();
            for(int i = 0; i < list1.size(); i++){
                if(list1[i].n == n){
                    list1.erase(list1.begin()+i);
                    break;
                }
            }
            return;
        }
        else{
            DFS(n+1, 0);
            DFS(n+1, 1);
            for(int i = 0; i < list1.size(); i++){
                if(list1[i].n == n){
                    list1.erase(list1.begin()+i);
                    break;
                }
            }
        }
    }
    else{
        list2.push_back(all_list[n]);
        if(n == pn-1){
            cal_min();
            for(int i = 0; i < list2.size(); i++){
                if(list2[i].n == n){
                    list2.erase(list2.begin()+i);
                    break;
                }
            }
            return;
        }
        else{
            DFS(n+1, 0);
            DFS(n+1, 1);
            for(int i = 0; i < list2.size(); i++){
                if(list2[i].n == n){
                    list2.erase(list2.begin()+i);
                    break;
                }
            }
        }
    }
}

void cal_min(){
    temp_min1 = 0;
    temp_min2 = 0;
    cal1.clear();
    cal2.clear();
    for(int i = 0; i < list1.size(); i++){
        cal1.push_back(list1[i].dist1);
    }
    for(int i = 0; i < list2.size(); i++){
        cal2.push_back(list2[i].dist2);
    }
    if(!cal1.empty()){
        sort(cal1.begin(), cal1.end());
    }
    if(!cal2.empty()){
        sort(cal2.begin(), cal2.end());
    }
    
    for(int i = 0; i < 3; i++){
        down[i] = 0;
    }
    cur_time = 0;
    down_size = 0;
    while(true){
        for(int i = 0; i < 3; i++){
            if(down[i] == 1){
                down[i]--;
                down_size--;
            }
            else if(down[i] > 1){
                down[i]--;
            }
        }
        if(down_size == 0 && cal1.empty()){
            temp_min1 = cur_time;
            break;
        }
        for(int i = 0; i < 3; i++){
            if(cal1.empty()){
                break;
            }
            if(cur_time >= cal1[0]){
                if(down_size == 3){
                    break;
                }
                for(int j = 0; j < 3; j++){
                    if(down[j] == 0){
                        down[j] = exit_dist[0];
                        cal1.erase(cal1.begin());
                        down_size++;
                        break;
                    }
                }
            }
        }
        cur_time++;
    }
    
    for(int i = 0; i < 3; i++){
        down[i] = 0;
    }
    cur_time = 0;
    down_size = 0;
    while(true){
        for(int i = 0; i < 3; i++){
            if(down[i] == 1){
                down[i]--;
                down_size--;
            }
            else if(down[i] > 1){
                down[i]--;
            }
        }
        if(down_size == 0 && cal2.empty()){
            temp_min2 = cur_time;
            break;
        }
        for(int i = 0; i < 3; i++){
            if(cal2.empty()){
                break;
            }
            if(cur_time >= cal2[0]){
                if(down_size == 3){
                    break;
                }
                for(int j = 0; j < 3; j++){
                    if(down[j] == 0){
                        down[j] = exit_dist[1];
                        cal2.erase(cal2.begin());
                        down_size++;
                        break;
                    }
                }
            }
        }
        cur_time++;
    }
    
    if(temp_min1 < temp_min2){
        if(res_min > temp_min2){
            res_min = temp_min2;
        }
    }
    else{
        if(res_min > temp_min1){
            res_min = temp_min1;
        }
    }
}



int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++){
        list1.clear();
        list2.clear();
        cal1.clear();
        cal2.clear();
        res_min = 999999999;
        pn = 0;
        en = 0;
        cin >> N;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> num;
                if(num == 0){
                    continue;
                }
                else if(num == 1){
                    people_xy_list[pn] = {i, j};
                    pn++;
                }
                else{
                    exit_xy_list[en] = {i, j};
                    exit_dist[en] = num;
                    en++;
                }
            }
        }
        
        for(int i = 0; i < pn; i++){
            all_list[i] = node{i, abs(people_xy_list[i].first-exit_xy_list[0].first)+abs(people_xy_list[i].second-exit_xy_list[0].second), abs(people_xy_list[i].first-exit_xy_list[1].first)+abs(people_xy_list[i].second-exit_xy_list[1].second)};
        }
        
        if(pn != 0){
            DFS(0, 0);
            DFS(0, 1);
        }
        
        cout << "#" << t << " " << res_min+1 << endl;
    }

    return 0;
}
