//
//  main.cpp
//  2068. 최대수 구하기
//
//  Created by JaeHyeob on 16/01/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    int num;
    int res = 0;
    
    for(int t = 0; t < testCase; t++){
        res = 0;
        for(int i = 0; i < 10; i++){
            cin >> num;
            if(res < num){
                res = num;
            }
        }
        cout << "#" << t+1 << " " << res << endl;
    }
    
    return 0;
}
