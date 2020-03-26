//
//  main.cpp
//  1234. 비밀번호
//
//  Created by JaeHyeob on 26/02/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

// stack 비어있으면 top() 실행시 오류 발생
// 항상 empty() 확인할 것

// cin은 공백과 엔터를 버퍼에 남김
// cin 후에 scanf() 사용할 경우, cin.ignore() 한번 실행해주기

#include <iostream>
#include <stack>

using namespace std;

stack<char> stk;
char res[100];

int main(int argc, const char * argv[]) {
    
    char c;
    int N;
    int s_size;
    
    for(int t = 1; t <= 10; t++){
        while(true){
            if(stk.empty()){
                break;
            }
            else{
                stk.pop();
            }
        }
        cin >> N;
        cin.ignore();
        
        for(int i = 0; i < N; i++){
            scanf("%1c", &c);
            if(stk.empty()){
                stk.push(c);
            }
            else if(stk.top() == c){
                stk.pop();
            }
            else{
                stk.push(c);
            }
        }
        
        s_size = stk.size();
        for(int j = s_size-1; j >= 0; j--){
            res[j] = stk.top();
            stk.pop();
        }
        
        cout << "#" << t << " ";
        for(int k = 0; k < s_size; k++){
            cout << res[k];
        }
        cout << endl;
    }
    
    return 0;
}
