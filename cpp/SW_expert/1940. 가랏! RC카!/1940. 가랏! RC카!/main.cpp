//
//  main.cpp
//  1940. 가랏! RC카!
//
//  Created by JaeHyeob on 15/02/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    int N = 0;
    int C1 = 0;
    int C2 = 0;
    
    int res = 0;
    int speed = 0;
    
    for(int t = 1; t <= testCase; t++){
        res = 0;
        speed = 0;
        cin >> N;
        for(int n = 1; n <= N; n++){
            cin >> C1;
            if(C1 == 1){
                cin >> C2;
                speed = speed + C2;
            }
            else if(C1 == 2){
                cin >> C2;
                speed = speed - C2;
                if(speed < 0){
                    speed = 0;
                }
            }
            res = res + speed;
        }
        
        cout << "#" << t << " " << res << endl;
    }
    
    return 0;
}
