//
//  main.cpp
//  soma_02
//
//  Created by JaeHyeob on 14/03/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

#include <iostream>

using namespace std;

int N, M;
int table[52][52];
string res = "YES";

void init_table(){
    for(int i = 0; i < 52; i++){
        for(int j = 0; j < 52; j++){
            table[i][j] = 0;
        }
    }
}

int search_node(int x, int y){
    if(table[x-1][y] == 1 && table[x-1][y-1] == 1 && table[x][y-1] == 1){
        return 1;
    }
    else if(table[x-1][y] == 1 && table[x-1][y+1] == 1 && table[x][y+1] == 1){
        return 1;
    }
    else if(table[x+1][y] == 1 && table[x+1][y-1] == 1 && table[x][y-1] == 1){
        return 1;
    }
    else if(table[x+1][y] == 1 && table[x+1][y+1] == 1 && table[x][y+1] == 1){
        return 1;
    }
    return 0;
}

void search_table(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(table[i][j] == 1){
                if(search_node(i, j) == 0){
                    res = "NO";
                    return;
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++){
        init_table();
        res = "YES";
        cin >> N >> M;
        for(int n = 1; n <= N; n++){
            for(int m = 1; m <= M; m++){
                cin >> table[n][m];
            }
        }
        
        search_table();
        cout << res << endl;
    }
    
    return 0;
}
