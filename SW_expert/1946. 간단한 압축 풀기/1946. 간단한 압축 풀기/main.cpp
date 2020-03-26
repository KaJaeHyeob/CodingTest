//
//  main.cpp
//  1946. 간단한 압축 풀기
//
//  Created by JaeHyeob on 15/02/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    int N = 0;
    char C = 0;
    int Cn = 0;
    int enter = 0;
    
    for(int t = 1; t <= testCase; t++){
        enter = 0;
        cout << "#" << t << endl;
        cin >> N;
        
        for(int n = 1; n <= N; n++){
            cin >> C;
            cin >> Cn;
            
            for(int i = 1; i <= Cn; i++){
                if(enter == 10){
                    cout << endl;
                    enter = 0;
                }
                cout << C;
                enter++;
            }
        }
        cout << endl;
    }
    
    return 0;
}
