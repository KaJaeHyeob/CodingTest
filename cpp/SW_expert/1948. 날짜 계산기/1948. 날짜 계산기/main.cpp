//
//  main.cpp
//  1948. 날짜 계산기
//
//  Created by JaeHyeob on 15/02/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

#include <iostream>

using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    int m1 = 0;
    int m2 = 0;
    int d1 = 0;
    int d2 = 0;
    int res = 0;
    
    for(int t = 1; t <= testCase; t++){
        cin >> m1 >> d1 >> m2 >> d2;
        
        res = 0;
        
        for(int i = m1; i < m2; i++){
            res = res + days[i];
        }
        
        res = res + d2 - d1 + 1;
        
        cout << "#" << t << " " << res << endl;
    }
    
    
    return 0;
}
