//
//  main.cpp
//  1954. 달팽이 숫자
//
//  Created by JaeHyeob on 15/02/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

#include <iostream>

using namespace std;

int way = 1; // 우 하 좌 상
int table[11][11];
int num = 1;

int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    int N;
    
    for(int t = 1; t <= testCase; t++){
        cin >> N;
        way = 1;
        num = 1;
        int a = 0;
        int b = 0;
        
        for(int i = 0; i < 11; i++){
            for(int j = 0; j < 11; j++){
                table[i][j] = -1;
            }
        }
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                table[i][j] = 0;
            }
        }
        
        while(true){
            table[a][b] = num;
            num++;
            if(way%4 == 1){
                if(table[a][b+1] != 0){
                    if(table[a+1][b] != 0){
                        break;
                    }
                    else{
                        way++;
                        a++;
                    }
                }
                else{
                    b++;
                }
            }
            else if(way%4 == 2){
                if(table[a+1][b] != 0){
                    if(table[a][b-1] != 0){
                        break;
                    }
                    else{
                        way++;
                        b--;
                    }
                }
                else{
                    a++;
                }
            }
            else if(way%4 == 3){
                if(table[a][b-1] != 0){
                    if(table[a-1][b] != 0){
                        break;
                    }
                    else{
                        way++;
                        a--;
                    }
                }
                else{
                    b--;
                }
            }
            else if(way%4 == 0){
                if(table[a-1][b] != 0){
                    if(table[a][b+1] != 0){
                        break;
                    }
                    else{
                        way++;
                        b++;
                    }
                }
                else{
                    a--;
                }
            }
        }
        
        cout << "#" << t << endl;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout << table[i][j] << " ";
            }
            cout << endl;
        }
        
    }
    
    return 0;
}
