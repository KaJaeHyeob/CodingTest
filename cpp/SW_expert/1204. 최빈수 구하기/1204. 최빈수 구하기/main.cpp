//
//  main.cpp
//  1204. 최빈수 구하기
//
//  Created by JaeHyeob on 17/02/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

#include <iostream>

using namespace std;

int table[101];

int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    int tc = 0;
    int num = 0;
    int max = 0;
    int res = 0;
    
    for(int t = 1; t <= testCase; t++){
        max = 0;
        res = 0;
        cin >> tc;
        
        for(int i = 0; i < 101; i++){
            table[i] = 0;
        }
        
        for(int i = 0; i < 1000; i++){
            cin >> num;
            table[num]++;
        }
        
        for(int i = 0; i < 101; i++){
            if(max <= table[i]){
                max = table[i];
                res = i;
            }
        }
        
        cout << "#" << t << " " << res << endl;
    }
    
    return 0;
}
