#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> t_copy;
vector<vector<string>> recover;
vector<string> answer;
bool already_find = false;

bool compare(vector<string> a, vector<string> b){
    return a[1] < b[1];
}

void DFS(string s){
    string temp = s;
    if(already_find == true){
        return;
    }
    if(t_copy.empty()){
        already_find = true;
        return;
    }
    for(int i = 0; i < t_copy.size(); i++){
        if(t_copy[i][0] == s){
            answer.push_back(t_copy[i][1]);
            recover.push_back(t_copy[i]);
            temp = t_copy[i][1];
            t_copy.erase(t_copy.begin()+i);
            
            DFS(temp);
            
            if(already_find == true){
                return;
            }
            
            t_copy.insert(t_copy.begin()+i, recover.back());
            recover.pop_back();
            answer.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    t_copy = tickets;
    sort(t_copy.begin(), t_copy.end());
    answer.push_back("ICN");
    string start = "ICN";
    DFS(start);
    
    return answer;
}
