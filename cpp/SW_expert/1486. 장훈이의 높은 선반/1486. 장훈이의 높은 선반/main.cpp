//
//  main.cpp
//  1486. 장훈이의 높은 선반
//
//  Created by JaeHyeob on 01/03/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

// unordered_set, iterator 사용 해결

// iterator 연습
// set iterator 사칙연산 불가능(for loop ++ 예외 가능), vector iterator 사칙연산 가능
// set iterator 사용 중 set.insert() 사용하면 set.begin(), set.end() 사이에 들어갈 수 있으므로 조심할 것

// 누적합 경우의 수 구하기
// 큰 배열 생성해서 해결

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<int> sum_list;
vector<int> temp_list;
int N, B;
int num = 0;
int res = 200000;
int temp;

int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++){
        res = 200000;
        cin >> N >> B;
        
        sum_list.clear();
        sum_list.insert(0);
        
        for(int n = 1; n <= N; n++){
            cin >> num;
            for(unordered_set<int>::iterator i = sum_list.begin(); i != sum_list.end(); i++){
                temp = *(i);
                temp_list.push_back(temp+num);
            }
            while(!temp_list.empty()){
                sum_list.insert(temp_list.back());
                temp_list.pop_back();
            }
        }
        
        for(unordered_set<int>::iterator i = sum_list.begin(); i != sum_list.end(); i++){
            temp = *(i);
            if(temp >= B){
                if(res > temp){
                    res = temp;
                }
            }
        }
        
        cout << "#" << t << " " << res-B << endl;
    }
    
    return 0;
}

/*
#include <iostream>
#include <vector>
 
using namespace std;

int main(){
    
    vector<int> asd;
    asd.push_back(12);
    asd.push_back(34);
    asd.push_back(56);
    asd.push_back(78);
    asd.push_back(90);
    
    vector<int>::iterator it1 = asd.begin();
    vector<int>::iterator it2 = asd.end();
    
    cout << *it1 << "\n" << *(asd.begin()+1) << "\n\n" << *it2 << "\n" << *(it2-1) << endl;
    
    return 0;
}
*/

/*
#include <iostream>
#include <set>

using namespace std;

int N, B;
int height_list[200001];
int sum = 0;
int num = 0;
int res = 0;

int main(int argc, const char * argv[]) {
    
    int testCase;
    cin >> testCase;
    
    for(int t = 1; t <= testCase; t++){
        sum = 0;
        cin >> N >> B;
        
        for(int i = 0; i <= N*10000; i++){
            height_list[i] = 0;
        }
        
        height_list[0] = 1;
        
        for(int n = 1; n <= N; n++){
            cin >> num;
            for(int i = sum; i >= 0; i--){
                if(height_list[i] == 1){
                    height_list[i+num] = 1;
                }
            }
            sum += num;
        }
        
        for(int i = B; i < N*10000; i++){
            if(height_list[i] == 1){
                res = i - B;
                break;
            }
        }
        
        cout << "#" << t << " " << res << endl;
    }
    
    return 0;
}
*/
