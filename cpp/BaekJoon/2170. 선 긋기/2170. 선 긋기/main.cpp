//
//  main.cpp
//  2170. 선 긋기
//
//  Created by JaeHyeob on 06/05/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

// 라인 스위핑 사용
// compare 함수 만들어서 sort() 사용

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int s, e;
};

int N;
vector<node> nodeList;
int s_n, e_n;
int temp_s, temp_e;
int res = 0;

bool compare(node a, node b){
    return a.s < b.s;
}

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for(int n = 1; n <= N; n++){
        cin >> s_n >> e_n;
        nodeList.push_back(node{s_n, e_n});
    }
    
    sort(nodeList.begin(), nodeList.end(), compare);
    
    s_n = nodeList[0].s;
    e_n = nodeList[0].e;
    
    for(int i = 1 ; i < N; i++){
        temp_s = nodeList[i].s;
        temp_e = nodeList[i].e;
        if(temp_s <= e_n){
            if(temp_e > e_n){
                e_n = temp_e;
            }
        }
        else{
            res = res + (e_n - s_n);
            s_n = temp_s;
            e_n = temp_e;
        }
    }
    
    res = res + (e_n - s_n);
    
    cout << res << '\n';
    
    return 0;
}
