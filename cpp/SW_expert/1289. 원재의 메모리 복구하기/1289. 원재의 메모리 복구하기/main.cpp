//
//  main.cpp
//  1289. 원재의 메모리 복구하기
//
//  Created by JaeHyeob on 19/02/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    string num;
    int start_index = 0;
    int res = 0;
    char state = '0';
    
    for(int t = 1; t <= testCase; t++){
        state = '0';
        res = 0;
        cin >> num;
        
        for(int i = 0; i < num.size(); i++){
            if(num[i] == '1'){
                start_index = i;
                res++;
                state = '1';
                break;
            }
        }
        
        for(int i = start_index; i < num.size(); i++){
            if(num[i] != state){
                state = num[i];
                res++;
            }
        }
        
        cout << "#" << t << " " << res << endl;
    }
    
    return 0;
}
