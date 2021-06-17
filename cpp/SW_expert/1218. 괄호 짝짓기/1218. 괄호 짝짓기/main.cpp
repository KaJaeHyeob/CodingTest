//
//  main.cpp
//  1218
//
//  Created by JaeHyeob on 23/09/2019.
//  Copyright © 2019 JaeHyeob. All rights reserved.
//

// 입력자료가 띄어쓰기 없이 주어질 경우
// 길이가 주어진다면 string으로 받은 후, 인덱스를 사용할 것

#include <iostream>
#include <stack>

using namespace std;

stack<char> my_stack;

int main() {
    
    while(true){
        if(my_stack.empty() == true){
            break;
        }
        else{
            my_stack.pop();
        }
    }
    
    int char_size;
    
    for(int t = 1; t <= 10; t++){
        
        while(true){
            if(my_stack.empty() == true){
                break;
            }
            else{
                my_stack.pop();
            }
        }
        
        cin >> char_size;
        
        string input_char;
        
        cin >> input_char;
        
        for(int i = 0; i < char_size; i++){
            
            char temp = input_char[i];
            
            if(temp == ')'){
                if(my_stack.top() == '('){
                    my_stack.pop();
                }
                else{
                    my_stack.push(temp);
                }
            }
            else if(temp == '}'){
                if(my_stack.top() == '{'){
                    my_stack.pop();
                }
                else{
                    my_stack.push(temp);
                }
            }
            else if(temp == '>'){
                if(my_stack.top() == '<'){
                    my_stack.pop();
                }
                else{
                    my_stack.push(temp);
                }
            }
            else if(temp == ']'){
                if(my_stack.top() == '['){
                    my_stack.pop();
                }
                else{
                    my_stack.push(temp);
                }
            }
            else{
                my_stack.push(temp);
            }
        }
        int res;
        if(my_stack.empty() == false){
            res = 0;
        }
        else{
            res = 1;
        }
        cout << "#" << t << " " << res << endl;
        
    }
    
    return 0;
}
