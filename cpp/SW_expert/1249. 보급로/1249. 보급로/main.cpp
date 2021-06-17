//
//  main.cpp
//  1249
//
//  Created by JaeHyeob on 17/09/2019.
//  Copyright © 2019 JaeHyeob. All rights reserved.
//

// 최단 거리 및 경로 구하기
// 다익스트라 사용

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int table_num[100][100];
int table_status[100][100];  // 1: unseen, 2: fringe, 3: tree
vector<pair<int, int>> table_connect[100][100];
vector<pair<int, int>> fringe_list;  // fringe list
int table_dist[100][100];  // distance
pair<int, int> table_pred[100][100];  // predecessor

// 메인
int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++){
        int N;
        cin >> N;
        
        int num;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                table_dist[i][j] = 99999;
                table_status[i][j] = 1;
                table_pred[i][j] = make_pair(-1, -1);
                
                scanf("%1d", &num);
                table_num[i][j] = num;
                
                table_connect[i][j].clear();
                if(i != 0){
                    table_connect[i][j].push_back(make_pair(i-1, j));
                }
                if(i != N-1){
                    table_connect[i][j].push_back(make_pair(i+1, j));
                }
                if(j != 0){
                    table_connect[i][j].push_back(make_pair(i, j-1));
                }
                if(j != N-1){
                    table_connect[i][j].push_back(make_pair(i, j+1));
                }
            }
        }
        
        table_dist[0][0] = 0;
        table_dist[0][1] = table_num[0][1];
        table_dist[1][0] = table_num[1][0];
        table_status[0][0] = 3;
        table_status[0][1] = 2;
        table_status[1][0] = 2;
        fringe_list.push_back(make_pair(0, 1));
        fringe_list.push_back(make_pair(1, 0));
        table_pred[0][1] = make_pair(0, 0);
        table_pred[1][0] = make_pair(0, 0);

        
        while(true){
            if(fringe_list.empty() == true){
                break;
            }
            int min_dist = 99999;
            int min_a = -1;
            int min_b = -1;
            int min_i = -1;
            for(int i = 0; i < fringe_list.size(); i++){
                if(min_dist > table_dist[fringe_list[i].first][fringe_list[i].second]){
                    min_dist = table_dist[fringe_list[i].first][fringe_list[i].second];
                    min_a = fringe_list[i].first;
                    min_b = fringe_list[i].second;
                    min_i = i;
                }
            }
            
            table_status[min_a][min_b] = 3;  // change from fringe to tree
            fringe_list.erase(fringe_list.begin()+min_i);
            for(int i = 0; i < table_connect[min_a][min_b].size(); i++){
                int connect_a = table_connect[min_a][min_b][i].first;
                int connect_b = table_connect[min_a][min_b][i].second;
                if(table_status[connect_a][connect_b] == 1){  // change from unseen to fringe
                    table_dist[connect_a][connect_b] = min_dist + table_num[connect_a][connect_b];
                    table_status[connect_a][connect_b] = 2;
                    fringe_list.push_back(make_pair(connect_a, connect_b));
                    table_pred[connect_a][connect_b] = make_pair(min_a, min_b);
                }
                else if(table_status[connect_a][connect_b] == 2){  // change from fringe to fringe
                    if(table_dist[connect_a][connect_b] > min_dist + table_num[connect_a][connect_b]){
                        table_dist[connect_a][connect_b] = min_dist + table_num[connect_a][connect_b];
                        table_pred[connect_a][connect_b] = make_pair(min_a, min_b);
                    }
                }
            }
        }
        
        cout << "#" << t << " " << table_dist[N-1][N-1] << endl;
        
    }
    
    
    return 0;
}
