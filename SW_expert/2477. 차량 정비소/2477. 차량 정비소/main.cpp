//
//  main.cpp
//  2477. 차량 정비소
//
//  Created by JaeHyeob on 02/03/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

// queue, vector 사용
// 1초 주기 반복문 사용

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class node{
public:
    node();
    node(int k, int t);
    int k; // 고객번호
    int t; // 입장시간
    int n; // N
};

node::node(){
}

node::node(int k, int t){
    this->k = k;
    this->t = t;
    n = 0;
}

queue<node> list1; // 대기라인1
queue<node> list2; // 대기라인2
vector<node> ing; // 처리중
int N;
int M;
int K;
int A;
int B;
int num;
int N_time[10];
int M_time[10];
int N_time_copy[10];
int M_time_copy[10];
int current_time = 0;
int res = 0;
node temp;

void lower(){
    for(int n = 1; n <= N; n++){
        if(N_time_copy[n] != 0){
            N_time_copy[n]--;
        }
    }
    for(int m = 1; m <= M; m++){
        if(M_time_copy[m] != 0){
            M_time_copy[m]--;
        }
    }
    current_time++;
}

void ing_to_list2(){
    for(int n = 1; n <= N; n++){
        if(N_time_copy[n] == 0){
            for(int i = 0; i < ing.size(); i++){
                if(ing[i].n == n){
                    temp = ing[i];
                    list2.push(temp);
                    ing.erase(ing.begin()+i);
                    break;
                }
            }
        }
    }
}

void list1_to_ing(){
    for(int n = 1; n <= N; n++){
        if(list1.empty()){
            break;
        }
        if(current_time < list1.front().t){
            break;
        }
        if(N_time_copy[n] == 0){
            N_time_copy[n] = N_time[n];
            temp = list1.front();
            temp.n = n;
            ing.push_back(temp);
            list1.pop();
        }
    }
}

void list2_to_finish(){
    for(int m = 1; m <= M; m++){
        if(list2.empty()){
            break;
        }
        if(M_time_copy[m] == 0){
            M_time_copy[m] = M_time[m];
            temp = list2.front();
            if(temp.n == A && m == B){
                res += temp.k;
            }
            list2.pop();
        }
    }
}

////////////////////////////////////////////////////////////////

int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++){
        current_time = 0;
        res = 0;
        cin >> N >> M >> K >> A >> B;
        
        for(int n = 1; n <= N; n++){
            cin >> N_time[n];
            N_time_copy[n] = 0;
        }
        for(int m = 1; m <= M; m++){
            cin >> M_time[m];
            M_time_copy[m] = 0;
        }
        
        for(int k = 1; k <= K; k++){
            cin >> num;
            list1.push(node(k, num));
        }
        
        while(true){
            if(list1.empty() && list2.empty() && ing.empty()){
                break;
            }
            
            if(!ing.empty()){
                ing_to_list2();
            }
            
            if(!list1.empty()){
                list1_to_ing();
            }
            
            if(!list2.empty()){
                list2_to_finish();
            }
            
            lower();
        }
        
        if(res == 0){
            cout << "#" << t << " " << -1 << endl;
        }
        else{
            cout << "#" << t << " " << res << endl;
        }
    }
    
    return 0;
}
