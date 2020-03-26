//
//  main.cpp
//  2493. 탑
//
//  Created by JaeHyeob on 07/03/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

// stack 구현
// cin 입력 한번에 전부 진행하는 게 빠름

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> list;
int arr[500001];

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    int num;
    
    for(int n = 1; n <= N; n++){
        cin >> arr[n];
    }
    
    list.push_back({0, 0});
    
    for(int n = 1; n <= N; n++){
        num = arr[n];
        while(true){
            if(list.empty()){
                cout << 0 << " ";
                list.push_back({n, num});
                break;
            }
            if(num >= list.back().second){
                list.pop_back();
                continue;
            }
            else{
                cout << list.back().first << " ";
                list.push_back({n, num});
                break;
            }
        }
    }
    
    return 0;
}
