//
//  main.cpp
//  1986. 지그재그 숫자
//
//  Created by JaeHyeob on 14/02/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    int num = 0;
    int res = 0;
    
    for(int t = 1; t <= testCase; t++){
        cin >> num;
        
        res = 0;
        for(int i = 0; i <= num; i++){
            if(i % 2 == 1){
                res = res + i;
            }
            else{
                res = res - i;
            }
        }
        
        cout << "#" << t << " " << res << endl;
    }
    
    return 0;
}
