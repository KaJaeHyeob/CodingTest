//
//  main.cpp
//  1208. Flatten
//
//  Created by JaeHyeob on 17/02/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

// algorithm 헤더파일에 있는 sort()는 퀵정렬을 사용하므로 nlog(n) 복잡도를 가짐
// 내림차순으로 정렬하고 싶을 경우, functional 헤더파일에 있는 greater<int>() 사용
// sort(v.begin(), v.end(), greater<int>());
// 디폴트는 오름차순으로 less<int>() 사용함

// 벡터 대신 배열 사용하면 더 빠름
// sort(a, a+100);

// 해당 층이 몇 개인지 배열에 저장하고 푸는 방법이 가장 빠름

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> list_num;

int main(int argc, const char * argv[]) {
    
    int N = 0;
    int num = 0;
    
    for(int t = 1; t <= 10; t++){
        list_num.clear();
        cin >> N;
        
        for(int i = 0; i < 100; i++){
            cin >> num;
            list_num.push_back(num);
        }
        
        sort(list_num.begin(), list_num.end());
        
        for(int n = 1; n <= N; n++){
            list_num[0]++;
            list_num[99]--;
            sort(list_num.begin(), list_num.end());
        }
        
        cout << "#" << t << " " << list_num[99] - list_num[0] << endl;
    }
    
    return 0;
}
