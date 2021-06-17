//
//  main.cpp
//  1213. String
//
//  Created by JaeHyeob on 16/02/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

// KMP 알고리즘 사용

#include <iostream>

using namespace std;

int F[11];

int main(int argc, const char * argv[]) {
    
    string patt;
    string input_str;
    int p_size = 0;
    int s_size = 0;
    int res = 0;
    int testCase = 0;
    
    for(int t = 1; t <= 10; t++){
        res = 0;
        
        cin >> testCase;
        cin >> patt;
        cin >> input_str;
        
        for(int i = 0; i < 11; i++){
            F[i] = 0;
        }
        
        p_size = patt.size();
        s_size = input_str.size();
        
        int j = 0;
        for(int i = 1; i < p_size; ){
            if(patt[i] == patt[j]){
                F[i] = j + 1;
                i++;
                j++;
            }
            else if(j > 0){
                j = F[j-1];
            }
            else{
                F[i] = 0;
                i++;
            }
        }
        
        j = 0;
        for(int i = 0; i < s_size; ){
            if(input_str[i] == patt[j]){
                if(j == p_size - 1){
                    // 위치 반환 경우, i - j 반환
                    res++;
                    i = i - (p_size-2);
                    j = 0;
                }
                else{
                    i++;
                    j++;
                }
            }
            else if(j > 0){
                j = F[j-1];
            }
            else{
                i++;
            }
        }
        
        cout << "#" << t << " " << res << endl;
    }
    
    return 0;
}
