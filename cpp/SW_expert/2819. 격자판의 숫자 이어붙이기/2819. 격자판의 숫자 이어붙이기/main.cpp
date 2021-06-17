//
//  main.cpp
//  2819
//
//  Created by JaeHyeob on 16/09/2019.
//  Copyright © 2019 JaeHyeob. All rights reserved.
//

// DFS 사용
// set, vector, pair 사용

// 격자판 임의의 위치에서 6번 이동하여 얻을 수 있는 7자리 숫자의 가능한 수
// set은 key 사용, key와 value가 같음
// map은 key와 value가 다름, 중복키 허용은 multimap
// https://hyeonstorage.tistory.com/327
// https://hyeonstorage.tistory.com/329

#include <iostream>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

int table[4][4];
set<int> nums;
vector<pair<int,int>> connect[4][4];

void df_search(int a, int b, int count_move, int res){
    if(count_move == 0){
        nums.insert(res+table[a][b]);
        return;
    }
    for(int i = 0; i < connect[a][b].size(); i++){
        df_search(connect[a][b][i].first, connect[a][b][i].second, count_move-1, res+table[a][b]*pow(10,count_move+1));
    }
}

int main() {
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i != 0){
                connect[i][j].push_back(make_pair(i-1, j));
            }
            if(i != 3){
                connect[i][j].push_back(make_pair(i+1, j));
            }
            if(j != 0){
                connect[i][j].push_back(make_pair(i, j-1));
            }
            if(j != 3){
                connect[i][j].push_back(make_pair(i, j+1));
            }
        }
    }
    
    int testCase;
    cin >> testCase;
    
    int num;
    
    for(int k = 1; k <= testCase; k++){
        
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cin >> num;
                table[i][j] = num;
            }
        }
        
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                df_search(i, j, 6, 0);
            }
        }
        
        cout << "#" << k << " " << nums.size() << endl;
        nums.clear();
        
    }
    
    
    return 0;
}
