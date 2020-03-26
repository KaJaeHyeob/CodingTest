//
//  main.cpp
//  2005. 파스칼의 삼각형
//
//  Created by JaeHyeob on 13/02/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int table[10][11];
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 11; j++){
            table[i][j] = 0;
        }
    }
    
    table[0][1] = 1;
    
    for(int i = 1; i < 10; i++){
        for(int j = 1; j <= i+1; j++){
            table[i][j] = table[i-1][j-1] + table[i-1][j];
        }
    }
    
    int testCase;
    cin >> testCase;
    
    int input_num = 0;
    
    for(int t = 1; t <= testCase; t++){
        cin >> input_num;
        cout << "#" << t << endl;
        for(int i = 0; i < input_num; i++){
            for(int j = 1; j <= i+1; j++){
                cout << table[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
