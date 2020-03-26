//
//  main.cpp
//  1206. View
//
//  Created by JaeHyeob on 17/02/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

// vector, algorithm 헤더파일의 max() 함수를 사용
// vector 말고 array 크게 생성해서 푸는 게 더 빠름
// int max = *max_element(v.begin(), v.end()) 표현도 알아둘 것

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> five_n;

int main(int argc, const char * argv[]) {
    
    int N = 0;
    int num = 0;
    int zero = 0;
    int i = 0;
    int max1 = 0;
    int max2 = 0;
    int max3 = 0;
    int res = 0;
    
    for(int t = 1; t <= 10; t++){
        i = 0;
        res = 0;
        five_n.clear();
        five_n.push_back(zero);
        five_n.push_back(zero);
        
        cin >> N;
        
        cin >> num;
        five_n.push_back(num);
        i++;
        cin >> num;
        five_n.push_back(num);
        i++;
        
        for(; i < N; i++){
            cin >> num;
            five_n.push_back(num);
            max1 = max(five_n[0], five_n[1]);
            max2 = max(five_n[3], five_n[4]);
            max3 = max(max1, max2);
            if(five_n[2] > max3){
                res += (five_n[2] - max3);
            }
            five_n.erase(five_n.begin());
        }
        
        five_n.push_back(zero);
        max1 = max(five_n[0], five_n[1]);
        max2 = max(five_n[3], five_n[4]);
        max3 = max(max1, max2);
        if(five_n[2] > max3){
            res += (five_n[2] - max3);
        }
        five_n.erase(five_n.begin());
        five_n.push_back(zero);
        max1 = max(five_n[0], five_n[1]);
        max2 = max(five_n[3], five_n[4]);
        max3 = max(max1, max2);
        if(five_n[2] > max3){
            res += (five_n[2] - max3);
        }
        five_n.erase(five_n.begin());
        
        cout << "#" << t << " " << res << endl;
    }
    
    return 0;
}
