//
//  main.cpp
//  Battle98. 유효숫자 표기
//
//  Created by JaeHyeob on 10/03/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

// string, char - int 비교할 땐 -48 기억하기

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++){
        cout << "#" << t << " ";
        string str;
        cin >> str;
        
        if(str[2] >= '5'){
            if(str[1] == '9'){
                if(str[0] == '9'){
                    cout << "1.0*10^" << str.size() << endl;
                    continue;
                }
                else{
                    cout << str[0]+1-48 << ".0*10^" << str.size()-1 << endl;
                    continue;
                }
            }
            else{
                cout << str[0] << "." << str[1]+1-48 << "*10^" << str.size()-1 << endl;
                continue;
            }
        }
        else{
            cout << str[0] << "." << str[1] << "*10^" << str.size()-1 << endl;
            continue;
        }
    }
    
    return 0;
}
