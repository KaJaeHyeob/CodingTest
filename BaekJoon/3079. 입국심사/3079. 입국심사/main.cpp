//
//  main.cpp
//  3079. 입국심사
//
//  Created by JaeHyeob on 21/04/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

#include <iostream>

using namespace std;

long long N, M;
long long Tk[100001];
long long temp = 1000000000;
long long min_t;
long long max_t;
long long mid_t;
long long res;

int main(int argc, const char * argv[]) {
    
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> Tk[i];
        if(temp > Tk[i]){
            temp = Tk[i];
        }
    }
    
    max_t = temp * M;
    min_t = 0;
    mid_t = (min_t + max_t) / 2;
    
    while(true){
        if(mid_t >= max_t){
            res = max_t;
            break;
        }
        
        temp = 0;
        for(int i = 1; i <= N; i++){
            temp += mid_t / Tk[i];
        }
        
        if(temp < M){
            min_t = mid_t + 1;
            mid_t = (min_t + max_t) / 2;
        }
        else{
            max_t = mid_t;
            mid_t = (min_t + max_t) / 2;
        }
    }
    
    cout << res << endl;
    
    
    return 0;
}
