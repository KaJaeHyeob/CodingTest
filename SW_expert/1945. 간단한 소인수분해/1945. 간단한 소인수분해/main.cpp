//
//  main.cpp
//  1945. 간단한 소인수분해
//
//  Created by JaeHyeob on 15/02/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    
    int testCase;
    cin >> testCase;
    
    int num;
    
    for(int t = 1; t <= testCase; t++){
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        e = 0;
        cin >> num;
        while(true){
            if(num % 2 != 0){
                break;
            }
            num = num / 2;
            a++;
        }
        while(true){
            if(num % 3 != 0){
                break;
            }
            num = num / 3;
            b++;
        }
        while(true){
            if(num % 5 != 0){
                break;
            }
            num = num / 5;
            c++;
        }
        while(true){
            if(num % 7 != 0){
                break;
            }
            num = num / 7;
            d++;
        }
        while(true){
            if(num % 11 != 0){
                break;
            }
            num = num / 11;
            e++;
        }
        
        cout << "#" << t << " " << a << " " << b << " " << c << " " << d << " " << e << endl;
    }
    
    
    
    return 0;
}
