//
//  main.cpp
//  3752
//
//  Created by JaeHyeob on 19/09/2019.
//  Copyright © 2019 JaeHyeob. All rights reserved.
//

// 점수 1부터 100까지 최대 100문제 가능한 점수 구하기

#include <iostream>
#include <unordered_set>

using namespace std;

bool table_bool[10001];

int main(){
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <=testCase; t++){
        
        int sum_num = 0;
        int count = 0;
        
        int num_size;
        cin >> num_size;
        
        table_bool[0] = true;
        
        for(int s = 0; s < num_size; s++){
            int num;
            cin >> num;
            
            sum_num = sum_num + num;
            
            for(int i = sum_num; i >= 0; i--){
                if(table_bool[i] == true){
                    table_bool[i + num] = true;
                }
            }
        }
        
        for(int k = sum_num; k >= 0; k--){
            if(table_bool[k] == true){
                count++;
                table_bool[k] = false;
            }
            
        }
        cout << "#" << t << " " << count << endl;
        
    }
    
    return 0;
}
