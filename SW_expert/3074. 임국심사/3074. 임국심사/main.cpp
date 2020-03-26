//
//  main.cpp
//  3074. 임국심사
//
//  Created by JaeHyeob on 29/02/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

// 이진탐색 사용
// 구하고자하는 답의 값을 가정해놓고, 수정해가는 방식

#include <iostream>

using namespace std;

long long tk_list[100000];

int main(int argc, const char * argv[]) {
    
    long long testCase;
    cin >> testCase;
    
    long long N, M;
    long long tk;
    long long max_tk = 0;
    long long t1, t2;
    long long mid;
    long long sum_m = 0;
    
    for(long long t = 1; t <= testCase; t++){
        max_tk = 0;
        cin >> N >> M;
        for(long long n = 0; n < N; n++){
            cin >> tk;
            tk_list[n] = tk;
            if(max_tk < tk){
                max_tk = tk;
            }
        }
        t2 = max_tk * M;
        t1 = 0;
        
        while(t1 < t2){
            sum_m = 0;
            mid = (t1 + t2) / 2;
            for(long long i = 0; i < N; i++){
                sum_m += mid / tk_list[i];
            }
            if(sum_m >= M){
                t2 = mid;
            }
            else{
                t1 = mid + 1;
            }
        }
        
        cout << "#" << t << " " << t2 << endl;
    }
    
    return 0;
}
