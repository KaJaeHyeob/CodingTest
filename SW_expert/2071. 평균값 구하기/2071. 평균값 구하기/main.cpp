//
//  main.cpp
//  2071. 평균값 구하기
//
//  Created by JaeHyeob on 16/01/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

// 반올림 구현은 0.5 더하고 floor 이용

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    double num = 0;
    double sum = 0;
    double res = 0;
    
    for(int t = 0; t < testCase; t++){
        sum = 0;
        res = 0;
        for(int i = 0; i < 10; i++){
            cin >> num;
            sum = sum + num;
        }
        res =  floor((sum / 10) + 0.5);
        cout << "#" << t+1 << " " << res << endl;
    }
    
    return 0;
}
