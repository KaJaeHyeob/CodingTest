//
//  main.cpp
//  11659. 구간 합 구하기 4
//
//  Created by JaeHyeob on 21/04/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

// cin 빠르게 하려면
// ios::sync_with_stdio(false);
// cin.tie(NULL);
// 사용할 것

#include <iostream>

using namespace std;

int a[100001], s[100001], n, m, x,y;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        cout << s[y]-s[x-1] << '\n';
    }
    
    return 0;
}
