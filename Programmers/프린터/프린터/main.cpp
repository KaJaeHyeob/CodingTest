#include <string>
#include <vector>

using namespace std;

int solution(vector<int> pri, int loc) {
    int answer = 0;
    
    int arr[10];
    for(int i = 0; i < 10; i++){
        arr[i] = 0;
    }
    for(int i = 0; i < pri.size(); i++){
        arr[pri[i]]++;
    }
    
    int loc_num = pri[loc];
    int cur_num = 9;
    int cur_index = pri.size();
    int TOF = 0;
    int for_minus = 0;
    
    while(true){
        if(loc_num == cur_num){
            if(loc < cur_index){
                for(int i = loc+1; i < cur_index; i++){
                    if(pri[i] == cur_num){
                        for_minus++;
                    }
                }
                return answer+arr[cur_num]-for_minus;
            }
            else{
                for(int i = cur_index+1; i <= loc; i++){
                    if(pri[i] == cur_num){
                        answer++;
                    }
                }
                return answer;
            }
        }
        TOF = 0;
        if(arr[cur_num] == 0){
            cur_num--;
            continue;
        }
        else{
            answer += arr[cur_num];
        }
        
        for(int i = cur_index-1; i >= 0; i--){
            if(pri[i] == cur_num){
                cur_index = i;
                TOF = 1;
                break;
            }
        }
        if(TOF == 1){
            cur_num--;
            continue;
        }
        else{
            for(int i = pri.size()-1; i >= cur_index+1; i--){
                if(pri[i] == cur_num){
                    cur_index = i;
                    break;
                }
            }
            cur_num--;
        }
    }
}
