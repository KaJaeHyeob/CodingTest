//
//  main.cpp
//  1211
//
//  Created by JaeHyeob on 25/09/2019.
//  Copyright © 2019 JaeHyeob. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int table_num[100][100];
int input_num;
queue<pair<pair<int, int>, int>> my_queue;
bool search_first = false;
int s_res = 0;
int g_size = 0;

void search_table(int x, int y, int way){  // way : 1up 2left 3right
    if(x == 0){
        if(search_first == false){
            search_first = true;
            s_res = y;
            return;
        }
    }
    if(way == 2){
        if(y == 0){
            my_queue.push(make_pair(make_pair(x-1, y), 1));
        }
        else{
            if(table_num[x][y-1] == 1){
                my_queue.push(make_pair(make_pair(x, y-1), 2));
            }
            else{
                my_queue.push(make_pair(make_pair(x-1, y), 1));
            }
        }
        
    }
    else if(way == 3){
        if(y == 99){
           my_queue.push(make_pair(make_pair(x-1, y), 1));
        }
        else{
            if(table_num[x][y+1] == 1){
               my_queue.push(make_pair(make_pair(x, y+1), 3));
            }
            else{
                my_queue.push(make_pair(make_pair(x-1, y), 1));
            }
        }
    }
    else{
        if(y-1 >= 0 && table_num[x][y-1] == 1){
            my_queue.push(make_pair(make_pair(x, y-1), 2));
        }
        else if(y+1 <= 99 && table_num[x][y+1] == 1){
            my_queue.push(make_pair(make_pair(x, y+1), 3));
        }
        else{
            my_queue.push(make_pair(make_pair(x-1, y), 1));
        }
    }
}


int main(int argc, const char * argv[]) {
    
    int testCase;
    
    for(int t = 1; t <= 10; t++){
        
        cin >> testCase;
        
        s_res = 0;
        g_size = 0;
        search_first = false;
        while(true){
            if(my_queue.empty() == true){
                break;
            }
            else{
                my_queue.pop();
            }
        }
        
        for(int i = 0; i < 99; i++){
            for(int j = 0; j < 100; j++){
                cin >> input_num;
                table_num[i][j] = input_num;
            }
        }
        for(int j = 0; j < 100; j++){
            cin >> input_num;
            table_num[99][j] = input_num;
            if(input_num == 1){
                my_queue.push(make_pair(make_pair(99, j), 1));
                g_size++;
            }
        }
        
        while(true){
            if(search_first == true){
                break;
            }
            for(int i = 0; i < g_size; i++){
                int x = my_queue.front().first.first;
                int y = my_queue.front().first.second;
                int way = my_queue.front().second;
                my_queue.pop();
                search_table(x, y, way);
            }
        }
        
        cout << "#" << t << " " << s_res << endl;
        
    }
    
    return 0;
}
