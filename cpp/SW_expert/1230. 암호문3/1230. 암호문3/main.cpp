//
//  main.cpp
//  1230. 암호문3
//
//  Created by JaeHyeob on 29/02/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

// vector.insert(), vector.erase() 사용

#include <iostream>
#include <vector>

using namespace std;

vector<int> list;

int main(int argc, const char * argv[]) {
    
    int N;
    int num;
    char c;
    int n1;
    int n2;
    
    for(int t = 1; t <= 10; t++){
        cin >> N;
        for(int n = 0; n < N; n++){
            cin >> num;
            list.push_back(num);
        }
        cin >> N;
        for(int n = 0; n < N; n++){
            cin >> c >> n1;
            if(c == 'I'){
                cin >> n2;
                for(int i = 0; i < n2; i++){
                    cin >> num;
                    list.insert(list.begin() + n1 + i, num);
                }
            }
            else if(c == 'D'){
                cin >> n2;
                for(int i = 0; i < n2; i++){
                    list.erase(list.begin() + n1);
                }
            }
            else if(c == 'A'){
                for(int i = 0; i < n1; i++){
                    cin >> num;
                    list.push_back(num);
                }
            }
        }
        
        cout << "#" << t << " ";
        for(int j = 0; j < 10; j++){
            cout << list[j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
