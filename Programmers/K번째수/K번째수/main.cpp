// vector.assign() 사용
// iterator [b, e) 주의할 것

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> temp;
    vector<int> res;
    int i, j, k;
    
    for(int m = 0; m < commands.size(); m++){
        temp.clear();
        i = commands[m][0];
        j = commands[m][1];
        k = commands[m][2];
        
        temp.assign(array.begin()+i-1, array.begin()+j);
        
        sort(temp.begin(), temp.end());
        
        res.push_back(temp[k-1]);
    }
    
    return res;
}
