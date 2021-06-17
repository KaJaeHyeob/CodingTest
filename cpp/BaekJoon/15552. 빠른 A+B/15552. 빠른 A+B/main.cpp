//
//  main.cpp
//  15552. 빠른 A+B
//
//  Created by JaeHyeob on 21/04/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testCase, a, b;
    
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++){
        cin >> a >> b;
        cout << a+b << '\n';
    }
    
    return 0;
}
