//
//  main.cpp
//  1989. 초심자의 회문 검사
//
//  Created by JaeHyeob on 14/02/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    string input_str;
    int str_size = 0;
    int ToF = 1;
    
    for(int t = 1; t <= testCase; t++){
        cin >> input_str;
        str_size = input_str.size();
        
        ToF = 1;
        for(int i = 0; i < str_size/2; i++){
            if(input_str[i] != input_str[str_size-i-1]){
                ToF = 0;
                break;
            }
        }
        
        cout << "#" << t << " " << ToF << endl;
    }
    
    return 0;
}
