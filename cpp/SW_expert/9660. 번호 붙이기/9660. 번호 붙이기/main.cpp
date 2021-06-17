//
//  main.cpp
//  9660. 번호 붙이기
//
//  Created by JaeHyeob on 10/03/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

#include <iostream>

using namespace std;

int N;
int hate_list[5001];
int use_list[5001];
long long res = 0;

void DFS(int n){
    if(n == N+1){
        res = (res + 1) % 1000000007;
        return;
    }
    
    for(int i = 1; i <= N; i++){
        if(use_list[i] == 0){
            if(hate_list[n] != i){
                use_list[i] = 1;
                DFS(n+1);
                use_list[i] = 0;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++){
        res = 0;
        cin >> N;
        fill_n(use_list, N+1, 0);
        for(int n = 1; n <= N; n++){
            cin >> hate_list[n];
        }
        DFS(1);
        cout << "#" << t << " " << res << endl;
    }
    
    return 0;
}

