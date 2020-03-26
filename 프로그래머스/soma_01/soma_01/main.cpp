//
//  main.cpp
//  soma_01
//
//  Created by JaeHyeob on 14/03/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    int a = N / 2;
    int b = N % 2;
    
    string res ="";
    
    if(b == 0){
        for(int i = 0; i < a; i++){
            res = res + "1";
        }
    }
    else{
        res = res + "7";
        for(int i = 0; i < a-1; i++){
            res = res + "1";
        }
    }
    
    cout << res << endl;
    
    return 0;
}
