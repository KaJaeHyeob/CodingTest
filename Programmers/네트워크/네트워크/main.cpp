// DFS, 재귀함수, 참조 사용

#include <string>
#include <vector>

using namespace std;

int finish[200];
int answer = 0;
int size;

void DFS(vector<vector<int>>& v, int n){
    finish[n] = 1;
    
    for(int i = 0 ; i < size; i++){
        if(v[n][i] == 1){
            if(finish[i] == 0){
                DFS(v, i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    size = computers.size();
    for(int i = 0; i < size; i++){
        finish[i] = 0;
    }
    
    for(int i = 0; i < size; i++){
        if(finish[i] == 0){
            answer++;
            DFS(computers, i);
        }
    }
    
    return answer;
}
