//
//  main.cpp
//  12100. 2048 (Easy)
//
//  Created by JaeHyeob on 13/05/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int table[20][20];
int res = 0;
queue<int> q;

void FindMax(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            res = max(res, table[i][j]);
        }
    }
}

void Move(int c){
    switch (c) {
        case 0:
            for(int j = 0; j < N; j++){
                for(int i = 0; i < N; i++){
                    if(table[i][j] != 0){
                        q.push(table[i][j]);
                    }
                    
                    int idx = 0;
                    while(!q.empty()){
                        int temp = q.front();
                        q.pop();
                        if(table[idx][j] == 0){
                            
                        }
                    }
                }
            }
            break;
            
    }
}

void DFS(int k){
    if(k == 5){
        FindMax();
        return;
    }
    int temp_table[20][20];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            temp_table[i][j] = table[i][j];
        }
    }
    
    for(int c = 0; c < 4; c++){
        Move(c);
        DFS(k+1);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                table[i][j] = temp_table[i][j];
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> table[i][j];
        }
    }
    
    return 0;
}
