//
//  main.cpp
//  1209. Sum
//
//  Created by JaeHyeob on 17/02/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

// i, j 를 교차하면 for문 한번으로도 가능함

#include <iostream>

using namespace std;

int table[100][100];

int main(int argc, const char * argv[]) {
    
    int testCase;
    int num = 0;
    int res = 0;
    int temp = 0;
    
    for(int t = 1; t <= 10; t++){
        res = 0;
        temp = 0;
        cin >> testCase;
        
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                cin >> num;
                table[i][j] = num;
            }
        }
        
        for(int i = 0; i < 100; i++){
            temp = 0;
            for(int j = 0; j < 100; j++){
                temp += table[i][j];
            }
            if(res < temp){
                res = temp;
            }
        }
        
        for(int j = 0; j < 100; j++){
            temp = 0;
            for(int i = 0; i < 100; i++){
                temp += table[i][j];
            }
            if(res < temp){
                res = temp;
            }
        }
        
        temp = 0;
        int i = 0;
        int j = 0;
        for(i = 0; i < 100; ){
            temp += table[i][j];
            i++;
            j++;
        }
        if(res < temp){
            res = temp;
        }
        
        temp = 0;
        i = 0;
        j = 99;
        for(i = 0; i < 100; ){
            temp += table[i][j];
            i++;
            j--;
        }
        if(res < temp){
            res = temp;
        }
        
        cout << "#" << t << " " << res << endl;
    }
    
    return 0;
}
