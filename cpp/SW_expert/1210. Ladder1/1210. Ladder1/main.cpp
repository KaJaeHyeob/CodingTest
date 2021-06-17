//
//  main.cpp
//  1210
//
//  Created by JaeHyeob on 22/09/2019.
//  Copyright © 2019 JaeHyeob. All rights reserved.
//

#include <iostream>

using namespace std;

int table_num[100][100];

void search_start(int a, int b){
    if(a == 0){
        cout << b << endl;
        return;
    }
    else{
        table_num[a][b] = 0;
        if(table_num[a][b-1] == 1 && b > 0){
            search_start(a, b-1);
            return;
        }
        else if(table_num[a][b+1] == 1 && b < 99){
            search_start(a, b+1);
            return;
        }
        else{
            search_start(a-1, b);
            return;
        }
    }
}


int main(int argc, const char * argv[]) {
    
    int testCase;
    int num;
    int g_a = 99;
    int g_b = 0;
    
    for(int t = 1; t <= 10; t++){
        cin >> testCase;
        
        for(int i = 0; i < 99; i++){
            for(int j = 0; j < 100; j++){
                cin >> num;
                table_num[i][j] = num;
            }
        }
        for(int i = 99; i < 100; i++){
            for(int j = 0; j < 100; j++){
                cin >> num;
                table_num[i][j] = num;
                if(num == 2){
                    g_b = j;
                }
            }
        }
        
        cout << "#" << t << " ";
        search_start(g_a, g_b);
        
    }
    
    return 0;
}
