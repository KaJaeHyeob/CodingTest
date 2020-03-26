//
//  main.cpp
//  1227
//
//  Created by JaeHyeob on 26/09/2019.
//  Copyright © 2019 JaeHyeob. All rights reserved.
//

// DFS 탐색 사용

#include <iostream>

using namespace std;

bool table_bool[100][100];

void change_bool(int a, int b){
    if(a < 0 || a >= 100 || b < 0 || b >= 100){
        return;
    }
    else if(table_bool[a][b] == false){
        table_bool[a][b] = true;
        change_bool(a-1, b);
        change_bool(a+1, b);
        change_bool(a, b-1);
        change_bool(a, b+1);
        return;
    }
    else{
        return;
    }
}

int main(int argc, const char * argv[]) {
    
    int testCase = 10;
    int t_num;
    
    int num = 0;
    int s_a = 0;;
    int s_b = 0;;
    int g_a = 0;;
    int g_b = 0;;
    
    for(int t = 1; t <= testCase; t++){
        
        cin >> t_num;
        
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j ++){
                scanf("%1d", &num);
                table_bool[i][j] = num;
                if(num == 2){
                    s_a = i;
                    s_b = j;
                    table_bool[i][j] = false;
                }
                else if(num == 3){
                    g_a = i;
                    g_b = j;
                    table_bool[i][j] = false;
                }
            }
        }
        
        change_bool(s_a, s_b);
        
        int res = 0;
        
        if(table_bool[g_a][g_b] == true){
            res = 1;
        }
        else{
            res = 0;
        }
        
        cout << "#" << t << " " << res << endl;
        
    }
    
    
    return 0;
}
