//
//  main.cpp
//  1244. 최대 상금
//
//  Created by JaeHyeob on 19/02/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

// 재귀함수를 이용한 DFS 구현


#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    string num;
    int N;
    int max = 0;
    int max_index = 0;
    int start_index = 0;
    char temp;
    bool dup = false;
    
    for(int t = 1; t <= testCase; t++){
        cin >> num;
        cin >> N;
        
        start_index = 0;
        
        for(int i = 0; i < num.size()-1; i++){
            for(int j = i+1; j < num.size(); j++){
                if(num[i] == num[j]){
                    dup = true;
                    break;
                }
            }
            if(dup == true){
                break;
            }
        }
        
        while(true){
            if(N == 0){
                break;
            }
            if(start_index == num.size() - 2){
                if(dup == true && num[start_index] > num[start_index+1]){
                    N = 0;
                    continue;
                }
                else{
                    temp = num[start_index];
                    num[start_index] = num[start_index+1];
                    num[start_index+1] = temp;
                    N--;
                    continue;
                }
            }
            
            max = num[start_index];
            max_index = start_index;
            
            for(int i = start_index; i < num.size(); i++){
                if(max <= num[i]){
                    max = num[i];
                    max_index = i;
                }
            }
            
            if(num[max_index] == num[start_index]){
                start_index++;
                continue;
            }
            else{
                temp = num[start_index];
                num[start_index] = num[max_index];
                num[max_index] = temp;
                start_index++;
                N--;
            }
        }
        
        cout << "#" << t << " " << num << endl;
    }
    
    return 0;
}


