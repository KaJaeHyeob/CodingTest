//
//  main.cpp
//  2206. 벽 부수고 이동하기
//
//  Created by JaeHyeob on 27/03/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

// DFS 했다가 실패
// 가중치가 없는 최단 거리를 찾는 문제의 경우, 대부분 BFS 사용
// 가중치가 있는 최단 거리를 찾는 문제의 경우, 완전탐색(BFS, DFS) 또는 다익스트라 사용

// 칸 이동 전에 != 0, != N 하나하나 비교해서 방향 정하지 말고,
// 칸 이동한 곳에서 >= 0 && < N 같이 한 번에 비교해서 결정할 것

#include <iostream>
#include <queue>

using namespace std;

struct node{
    int x;
    int y;
    int dist;
    bool breaking;
};

queue<node> q;
int N, M;
int table[1000][1000];
int bool_pass[1000][1000][2];
int res = -1;
int dx[4] = {-1, 0, 1, 0}; // N E S W
int dy[4] = {0, 1, 0, -1};

void BFS(){
    while(true){
        if(q.empty()){
            return;
        }
        
        node temp = q.front();
        q.pop();
        int tx = temp.x;
        int ty = temp.y;
        int td = temp.dist;
        bool tb = temp.breaking;
        
        if(tx == N-1 && ty == M-1){
            res = td;
            return;
        }
        
        for(int i = 0; i < 4; i++){
            int ttx = tx+dx[i];
            int tty = ty+dy[i];
            
            if(ttx >= 0 && ttx <= N-1 && tty >= 0 && tty <= M-1){
                if(table[ttx][tty] == 1){
                    if(tb == false){
                        bool_pass[ttx][tty][1] = 1;
                        q.push(node{ttx, tty, td+1, true});
                    }
                }
                else{
                    if(tb == false){
                        if(bool_pass[ttx][tty][0] == 0){
                            bool_pass[ttx][tty][0] = 1;
                            q.push(node{ttx, tty, td+1, tb});
                        }
                    }
                    else{
                        if(bool_pass[ttx][tty][1] == 0){
                            bool_pass[ttx][tty][1] = 1;
                            q.push(node{ttx, tty, td+1, tb});
                        }
                    }
                }
            }
        } // for quit
        
    } // while quit
}

int main(int argc, const char * argv[]) {
    
    scanf("%d %d", &N, &M);
    for(int n = 0; n < N; n++){
        for(int m = 0; m < M; m++){
            scanf("%1d", &table[n][m]);
        }
    }
    
    q.push(node{0, 0, 1, false});
    bool_pass[0][0][0] = 1;
    BFS();
    
    cout << res << endl;
    
    return 0;
}


/*
#include <iostream>

using namespace std;

int N, M;
int table[1000][1000];
int bool_pass[1000][1000];
int dist = 0;
int res = 999999999;
bool break_wall = false;

void DFS(int x, int y){
    dist++;
    bool_pass[x][y] = 1;
    
    if(dist >= res){
        dist--;
        bool_pass[x][y] = 0;
        return;
    }
    
    if(x == N-1 && y == M-1){
        if(dist < res){
            res = dist;
        }
        dist--;
        bool_pass[x][y] = 0;
        return;
    }
    
    if(x != 0 && bool_pass[x-1][y] == 0){
        if(table[x-1][y] == 1){
            if(break_wall == false){
                break_wall = true;
                DFS(x-1, y);
                break_wall = false;
            }
        }
        else{
            DFS(x-1, y);
        }
    }
    if(x != N-1 && bool_pass[x+1][y] == 0){
        if(table[x+1][y] == 1){
            if(break_wall == false){
                break_wall = true;
                DFS(x+1, y);
                break_wall = false;
            }
        }
        else{
            DFS(x+1, y);
        }
    }
    if(y != 0 && bool_pass[x][y-1] == 0){
        if(table[x][y-1] == 1){
            if(break_wall == false){
                break_wall = true;
                DFS(x, y-1);
                break_wall = false;
            }
        }
        else{
            DFS(x, y-1);
        }
    }
    if(y != M-1 && bool_pass[x][y+1] == 0){
        if(table[x][y+1] == 1){
            if(break_wall == false){
                break_wall = true;
                DFS(x, y+1);
                break_wall = false;
            }
        }
        else{
            DFS(x, y+1);
        }
    }
    
    dist--;
    bool_pass[x][y] = 0;
}

int main(int argc, const char * argv[]) {
    
    scanf("%d %d", &N, &M);
    for(int n = 0; n < N; n++){
        for(int m = 0; m < M; m++){
            scanf("%1d", &table[n][m]);
        }
    }
    
    DFS(0,0);
    
    cout << ((res == 999999999) ? -1 : res) << endl;
    
    return 0;
}
*/
