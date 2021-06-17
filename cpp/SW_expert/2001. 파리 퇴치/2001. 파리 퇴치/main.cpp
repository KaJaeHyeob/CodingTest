//
//  main.cpp
//  2001. 파리 퇴치
//
//  Created by JaeHyeob on 14/02/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

#include <iostream>

using namespace std;

int tableA[15][15];

int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    int N = 0;
    int M = 0;
    int num = 0;
    int res = 0;
    int final_res = 0;
    
    for(int t = 1; t <= testCase; t++){
        cin >> N;
        cin >> M;
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> num;
                tableA[i][j] = num;
            }
        }
        
        for(int i = 0; i <= N-M; i++){
            for(int j = 0; j <= N-M; j++){
                res = 0;
                for(int ii = i; ii < i+M; ii++){
                    for(int jj = j; jj < j+M; jj++){
                        res = res + tableA[ii][jj];
                    }
                }
                if(final_res < res){
                    final_res = res;
                }
            }
        }
        
        cout << "#" << t << " " << final_res << endl;
        final_res = 0;
    }
    
    
    return 0;
}
