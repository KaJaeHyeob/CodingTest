//
//  main.cpp
//  2007. 패턴 마디의 길이
//
//  Created by JaeHyeob on 13/02/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

/*
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string input_mseg;
    bool ToF = true;
    int res;
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++){
        cin >> input_mseg;
        ToF = true;
        
        for(int i = 10; ; i--){
            if(input_mseg[0] == input_mseg[i]){
                for(int j = 1; j < i; j++){
                    if(input_mseg[j] != input_mseg[i + j]){
                        ToF = false;
                        break;
                    }
                }
                if(ToF == true){
                    res = i;
                    break;
                }
                else{
                    ToF = true;
                }
            }
        }
        
        cout << "#" << t << " " << res << endl;
    }
    
    return 0;
}
 */

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string input_mseg;
    bool ToF = true;
    int res = 0;
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++){
        cin >> input_mseg;
        ToF = true;
        
        for(int i = 1; i < 10 ; i++){
            if(input_mseg[0] == input_mseg[i]){
                for(int j = 1; j < i; j++){
                    if(input_mseg[j] != input_mseg[i + j]){
                        ToF = false;
                        break;
                    }
                }
                if(ToF == true){
                    res = i;
                    break;
                }
                else{
                    ToF = true;
                }
            }
        }
        
        cout << "#" << t << " " << res << endl;
    }
    
    return 0;
}
