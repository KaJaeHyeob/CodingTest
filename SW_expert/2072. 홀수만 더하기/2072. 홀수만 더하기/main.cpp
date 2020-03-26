//
//  main.cpp
//  2072. 홀수만 더하기
//
//  Created by JaeHyeob on 16/01/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    int res = 0;
    int num = 0;
    
    for(int t = 0; t < testCase; t++){
        res = 0;
        for(int j = 0; j < 10; j++){
            cin >> num;
            if(num % 2 == 1){
                res = res + num;
            }
        }
        cout << "#" << t+1 << " " << res << endl;
    }
    
    return 0;
}
