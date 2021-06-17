// DFS 사용
// sum 전역변수가 아니라 DFS 함수 인자로 사용하면 훨씬 깔끔함

// 참조, 포인터 연습하기

/*
int main(){
    int a = 1;
    int* b = &a; // 포인터 변수 b = a 주소값
    
    cout << "a = " << a << endl;
    cout << "&a = " << &a << endl;
    cout << "b = " << b << endl;
    cout << "*b = " << *b << endl; // 포인터 변수 b 역참조
    
    int& c = a; // 참조 변수 c = a
    cout << "c = " << c << endl;
    cout << "c++ = " << c++ << endl;
    cout << "a = " << a << endl;
    cout << "c = " << c << endl;
}
 */

/*
#include <string>
#include <vector>

using namespace std;

int sum = 0;
int res = 0;
vector<int> num;
int size;
int tar;

void dfs(int i, int sign){
    if(sign == 1){
        sum += num[i];
    }
    else{
        sum -= num[i];
    }
    
    if(i == size - 1){
        if(sum == tar){
            res++;
        }
        
        if(sign == 1){
            sum -= num[i];
        }
        else{
            sum += num[i];
        }
        return;
    }
    
    dfs(i+1, 1);
    dfs(i+1, 2);
    
    if(sign == 1){
        sum -= num[i];
    }
    else{
        sum += num[i];
    }
}

int solution(vector<int> numbers, int target) {
    sum = 0;
    res = 0;
    num = numbers;
    tar = target;
    size = numbers.size();
    
    dfs(0, 1);
    dfs(0, 2);
    
    return res;
}
*/

#include <string>
#include <vector>

using namespace std;

int total;

void DFS(vector<int> &numbers, int &target,int sum,int n) {
    if(n >= numbers.size()){
        if(sum == target) total++;
        return;
    }
    
    DFS(numbers, target, sum + numbers[n], n+1);
    DFS(numbers, target, sum - numbers[n], n+1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    DFS(numbers, target, numbers[0] , 1);
    DFS(numbers, target, -numbers[0], 1);
    
    answer = total;
    
    return answer;
}
