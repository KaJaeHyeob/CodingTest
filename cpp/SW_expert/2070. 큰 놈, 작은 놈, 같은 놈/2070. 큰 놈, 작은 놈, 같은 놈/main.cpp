//
//  main.cpp
//  2070. 큰 놈, 작은 놈, 같은 놈
//
//  Created by JaeHyeob on 16/01/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    int num1;
    int num2;
    
    for(int t = 0; t < testCase; t++){
        cin >> num1;
        cin >> num2;
        
        cout << "#" << t+1 << " ";
        
        if(num1 == num2){
            cout << "=";
        }
        else if(num1 > num2){
            cout << ">";
        }
        else{
            cout << "<";
        }
        
        cout << endl;
    }
    
    return 0;
}
