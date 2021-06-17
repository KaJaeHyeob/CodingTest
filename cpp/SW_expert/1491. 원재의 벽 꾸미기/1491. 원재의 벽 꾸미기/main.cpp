//
//  main.cpp
//  1491. 원재의 벽 꾸미기
//
//  Created by JaeHyeob on 19/02/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

// 뭔가 큰 수가 나올 것 같으면 long long 사용할 것
// 최댓값은 자료형_MAX 또는 __자료형_MAX__ 사용할 것

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    long long N = 0;
    long long A = 0;
    long long B = 0;
    long long R = 1;
    long long C = 1;
    long long min_res = __LONG_LONG_MAX__;
    long long temp = 0;
    
    for(int t = 1; t <= testCase; t++){
        min_res = __LONG_LONG_MAX__;
        R = 1;
        C = 1;
        cin >> N >> A >> B;
        
        for(; R <= N; R++){
            C = 1;
            for(; C <= N/R; C++){
                temp = A * abs(R - C) + B * (N - R * C);
                min_res = min(min_res, temp);
            }
        }
        
        cout << "#" << t << " " << min_res << endl;
    }
    
    return 0;
}
