//
//  main.cpp
//  soma_03
//
//  Created by JaeHyeob on 14/03/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

#include <iostream>

using namespace std;

int table[3001];
int k_index[3001];
int N;
int K;
int cost = 999999999;
int cost_temp = 0;
int complete = 0;

void k_init();
void k_plus();
void k_update();
void search_cost();

void k_init(){
    for(int i = 1; i <= K; i++){
        k_index[i] = i;
    }
}

void k_plus(){
    if(k_index[K] == N-1){
        k_update();
    }
    else{
        k_index[K]++;
    }
}

void k_update(){
    int minus = -1;
    for(int i = K + minus; i >= 1; i = K + minus){
        if(k_index[i] == N + minus - 1){
            if(i == 1){
                complete = 1;
                return;
            }
            else{
                minus--;
                continue;
            }
        }
        else{
            k_index[i]++;
            for(int j = i+1; j <= K; j++){
                k_index[j] = k_index[j-1] + 1;
            }
            return;
        }
    }
}

void search_cost(){
    cost_temp = 0;
    cost_temp -= table[1];
    cost_temp += table[N];
    for(int k = 1; k <= K; k++){
        cost_temp += table[k_index[k]];
        cost_temp -= table[k_index[k]+1];
    }
    if(cost > cost_temp){
        cost = cost_temp;
    }
}

int main(int argc, const char * argv[]) {
    table[0] = -1;
    
    cin >> N >> K;
    K--; // 구분점 개수로 사용
    for(int n = 1; n <= N; n++){
        cin >> table[n];
    }
    
    if(K == 0){
        cout << table[N] - table[1] << endl;
        return 0;
    }
    
    k_init();

    while(true){
        search_cost();
        k_plus();
        if(complete == 1){
            break;
        }
    }
    
    cout << cost << endl;
    return 0;
}
