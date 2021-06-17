//
//  main.cpp
//  1219
//
//  Created by JaeHyeob on 22/09/2019.
//  Copyright © 2019 JaeHyeob. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> table_road[100];
bool res_bool = false;

void search_table(int a){
    if(a == 99){
        res_bool = true;
        return;
    }
    int n1 = 0;
    int n2 = 0;
    if(table_road[a].size() == 1){
        n1 = table_road[a][0];
        table_road[a].clear();
        search_table(n1);
        return;
    }
    else if(table_road[a].size() == 2){
        n1 = table_road[a][0];
        n2 = table_road[a][1];
        table_road[a].clear();
        search_table(n1);
        search_table(n2);
        return;
    }
}

void clear_table(){
    for(int i = 0; i < 100; i++){
        table_road[i].clear();
    }
}

int main(int argc, const char * argv[]) {
    
    int testCase;
    
    for(int t = 1; t <= 10; t++){
        
        cin >> testCase;
        
        res_bool = false;
        clear_table();
        
        int num_road;
        cin >> num_road;
        
        int s_a;
        int s_b;
        
        for(int i = 0; i < num_road; i++){
            cin >> s_a;
            cin >> s_b;
            table_road[s_a].push_back(s_b);
        }
        
        search_table(0);
        
        cout << "#" << t << " ";
        if(res_bool == true){
            cout << "1" << endl;
        }
        else{
            cout << "0" << endl;
        }
            
    }
    
    
    
    return 0;
}
