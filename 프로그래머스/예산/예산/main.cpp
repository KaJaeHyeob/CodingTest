// 이진탐색 사용

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> b_copy;
int min_num;
int max_num;
int b_size;
int mid_num;
long sum;
int answer = -1;


int solution(vector<int> budgets, int M) {
    b_copy = budgets;
    sort(b_copy.begin(), b_copy.end());
    b_size = b_copy.size();
    answer = -1;
    min_num = 1;
    max_num = b_copy[b_size-1];
    mid_num = (min_num+max_num) / 2;
    
    while(true){
        sum = 0;
        for(int i = 0; i < b_size; i++){
            if(mid_num <= b_copy[i]){
                sum += (b_size-i) * mid_num;
                break;
            }
            else{
                sum += b_copy[i];
            }
            
            if(sum > M){
                max_num = mid_num-1;
                mid_num = (min_num+max_num) / 2;
                if(max_num <= min_num){
                    answer = min_num;
                }
                break;
            }
        }
        
        if(sum == M){
            answer = mid_num;
        }
        else if(sum < M){
            if(min_num == mid_num){
                if(mid_num == max_num){
                    answer = mid_num;
                }
                else{
                    mid_num = max_num;
                    continue;
                }
            }
            min_num = mid_num;
            mid_num = (min_num+max_num) / 2;
        }
        else if(sum > M){
            max_num = mid_num-1;
            mid_num = (min_num+max_num) / 2;
            if(max_num <= min_num){
                answer = min_num;
            }
        }
        
        if(answer != -1){
            break;
        }
    }
    
    return answer;
}
