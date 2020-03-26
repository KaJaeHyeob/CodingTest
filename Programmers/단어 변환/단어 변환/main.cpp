// BFS 사용
// 다음부턴 vector 대신 queue 연습해볼 것

#include <string>
#include <vector>

using namespace std;

int str_size;
int vec_size;
bool used[50];
vector<int> adj_list[51];
vector<int> temp;
int cur_time = 1;

bool adj(string a, string b){
    int count = 0;
    for(int i = 0; i < str_size; i++){
        if(a[i] != b[i]){
            count++;
            if(count >= 2){
                return false;
            }
        }
    }
    return true;
}

void make_adj(vector<string>& w, string& begin){
    for(int i = 0; i < vec_size; i++){
        for(int j = 0; j < vec_size; j++){
            if(adj(w[i], w[j]) == true){
                if(i == j){
                    continue;
                }
                else{
                    adj_list[i].push_back(j);
                }
            }
        }
    }
    for(int i = 0; i < vec_size; i++){
        if(adj(begin, w[i]) == true){
            adj_list[50].push_back(i);
        }
    }
}

void BFS(vector<string>& w, string& target){
    for(int i = 0; i < adj_list[50].size(); i++){
        temp.push_back(adj_list[50][i]);
        used[adj_list[50][i]] = 1;
    }
    
    int index = 0;
    int cur_size = 0;
    
    while(true){
        if(temp.empty()){
            cur_time = 0;
            return;
        }
        
        cur_size = temp.size();
        
        for(int i = 0; i < cur_size; i++){
            index = *temp.begin();
            
            for(int j = 0; j < adj_list[index].size(); j++){
                if(used[adj_list[index][j]] == 0){
                    temp.push_back(adj_list[index][j]);
                    used[adj_list[index][j]] = 1;
                }
            }
            
            temp.erase(temp.begin());
            if(w[index] == target){
                return;
            }
        }
        
        cur_time++;
    }
}


int solution(string begin, string target, vector<string> words) {
    
    str_size = begin.size();
    vec_size = words.size();
    
    for(int i = 0; i < vec_size; i++){
        used[i] = 0;
    }
    
    make_adj(words, begin);
    BFS(words, target);
   
    return cur_time;
}
