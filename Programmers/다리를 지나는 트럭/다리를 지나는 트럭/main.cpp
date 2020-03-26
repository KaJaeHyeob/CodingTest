#include <string>
#include <vector>

using namespace std;

int solution(int length, int weight, vector<int> truck_w) {
    
    vector<int> ing_w;
    vector<int> ing_t;
    
    int sum_w = 0;
    int cur_t = 0;
    
    while(true){
        
        if(!ing_t.empty()){
            if(ing_t[0] == 1){
                sum_w -= ing_w[0];
                ing_t.erase(ing_t.begin());
                ing_w.erase(ing_w.begin());
            }
            for(int i = 0; i < ing_t.size(); i++){
                ing_t[i]--;
            }
        }
        
        if(truck_w.empty() && ing_w.empty()){
            return cur_t + 1;
        }
        
        if(truck_w.empty()){
            cur_t++;
            continue;
        }
        
        if(sum_w + truck_w[0] <= weight){
            ing_w.push_back(truck_w[0]);
            ing_t.push_back(length);
            sum_w += truck_w[0];
            truck_w.erase(truck_w.begin());
            cur_t++;
            continue;
        }
        else{
            cur_t++;
            continue;
        }
    }
}
