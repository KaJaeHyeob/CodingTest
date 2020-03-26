//
//  main.cpp
//  1240. 단순 2진 암호코드
//
//  Created by JaeHyeob on 25/02/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

// 문자열 비교는 ==, strcmp(), string.compare() 사용
// strcmp()는 ==이면 0 반환, >이면 1 반환, <이면 -1 반환
// 문자열 탐색은 string.find(), string.rfind() 사용

#include <iostream>
#include <string>

using namespace std;

int change_SI(string s){
    int res = 0;
    if(s == "0001101"){
        res = 0;
    }
    else if(s == "0011001"){
        res = 1;
    }
    else if(s == "0010011"){
        res = 2;
    }
    else if(s == "0111101"){
        res = 3;
    }
    else if(s == "0100011"){
        res = 4;
    }
    else if(s == "0110001"){
        res = 5;
    }
    else if(s == "0101111"){
        res = 6;
    }
    else if(s == "0111011"){
        res = 7;
    }
    else if(s == "0110111"){
        res = 8;
    }
    else if(s == "0001011"){
        res = 9;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    int N, M;
    string str;
    int last_index = 0;
    string temp;
    int table[8];
    int res = 0;
    
    for(int t = 1; t <= testCase; t++){
        last_index = 0;
        res = 0;
        
        cin >> N >> M;
        
        for(int n = 1; n <= N; n++){
            cin >> str;
            if(last_index != 0){
                continue;
            }
            for(int m = 0; m < M; m++){
                if(str[m] == '1'){
                    last_index = m;
                }
            }
            if(last_index != 0){
                last_index += 1;
                for(int i = 7; i >= 0; i--){
                    temp = str.substr(last_index-7, 7);
                    table[i] = change_SI(temp);
                    last_index -= 7;
                }
            }
        }
        
        if(((table[0] + table[2] + table[4] + table[6]) * 3 + table[1] + table[3] + table[5] + table[7]) % 10 == 0){
            for(int j = 0; j < 8; j++){
                res += table[j];
            }
            cout << "#" << t << " " << res << endl;
        }
        else{
            cout << "#" << t << " " << 0 << endl;
        }
    }
    
    return 0;
}
