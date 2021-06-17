// 비교 함수 compare() 만들어서 sort() 실행
// compare(int, int) 안에서 to_string() 실행하는 것보다
// 미리 string list 만들고 compare(string, string) 실행하는 게 훨씬 빠르다

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    
    vector<string> temp;
    for(int i = 0; i < numbers.size(); i++){
        temp.push_back(to_string(numbers[i]));
    }
    
    sort(temp.begin(), temp.end(), compare);
    
    string answer = "";
    
    if(temp[0] == "0"){
        return "0";
    }
    else{
        for(int i = 0; i < temp.size(); i++){
            answer += temp[i];
        }
        return answer;
    }
}
