//
//  main.cpp
//  10216. Count Circle Groups
//
//  Created by JaeHyeob on 26/03/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

// BFS, set 사용
// set 자료구조는 push(), pop() 없고, insert(), erase() 사용
// sqrt(), pow() 등의 math.h 헤더파일 함수는 시간이 굉장히 오래 걸림
// 최대한 사용 안 하는 것이 좋음

// iterator 연습

#include <iostream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

struct node{
    int x;
    int y;
    int r;
};

node node_list[3001];
int N;
int input_x;
int input_y;
int input_r;
int res = 0;
bool bool_finish = false;
set<int> cur_grp_index;
bool bool_handle[3001];

void isFinish(){
    for(int i = 1; i <= N; i++){
        if(bool_handle[i] == false){
            cur_grp_index.insert(i);
            res++;
            return;
        }
    }
    bool_finish = true;
    return;
}

void BFS(int n){
    bool_handle[n] = true;
    for(int i = 1; i <= N; i++){
        if(bool_handle[i] == true){
            continue;
        }
        else{
            int dist = (node_list[n].x - node_list[i].x)*(node_list[n].x - node_list[i].x) + (node_list[n].y - node_list[i].y)*(node_list[n].y - node_list[i].y);
            if(dist <= (node_list[n].r + node_list[i].r)*(node_list[n].r + node_list[i].r)){
                cur_grp_index.insert(i);
            }
        }
    }
    if(cur_grp_index.empty()){
        return;
    }
    else{
        int next_n = *cur_grp_index.begin();
        cur_grp_index.erase(cur_grp_index.begin());
        BFS(next_n);
    }
}

int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++){
        bool_finish = false;
        res = 0;
        cin >> N;
        for(int n = 1; n <= N; n++){
            cin >> input_x >> input_y >> input_r;
            node_list[n] = node{input_x, input_y, input_r};
            bool_handle[n] = false;
        }
        
        while(true){
            isFinish();
            if(bool_finish){
                break;
            }
            
            int start = *cur_grp_index.begin();
            cur_grp_index.erase(cur_grp_index.begin());
            BFS(start);
        }
        
        cout << res << endl;
    }
    
    return 0;
}

/*
#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);

    cout << *test.end() << endl;
    cout << *(test.end()-1) << endl;
    
    for(int i = 0; i < test.size(); i++){
        cout << test[i] << " ";
    }
    cout << endl;
    
    test.erase(test.begin()+1, test.end()-2);
    
    for(int i = 0; i < test.size(); i++){
        cout << test[i] << " ";
    }
    cout << endl;
    
    test.push_back(6);
    test.push_back(7);
    
    for(int i = 0; i < test.size(); i++){
        cout << test[i] << " ";
    }
    cout << endl;
    
    test.erase(test.begin()+1, test.begin()+3);

    for(int i = 0; i < test.size(); i++){
        cout << test[i] << " ";
    }
    cout << endl;
    
    return 0;
}
*/
