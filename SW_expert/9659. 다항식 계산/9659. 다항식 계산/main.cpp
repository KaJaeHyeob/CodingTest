//
//  main.cpp
//  9659. 다항식 계산
//
//  Created by JaeHyeob on 10/03/2020.
//  Copyright © 2020 JaeHyeob. All rights reserved.
//

// fill_n(arr, size, value) 기억하기
// fill_n(&arr[n], size, value) 사용함
// cin, cout - scanf(), printf() 시간 차이 없음
// 입출력을 연속적으로 사용하는 것은 시간 측면에서 중요함 (약 10배 차이)

#include <iostream>

using namespace std;

long long f_num[51];
int N;
int M;
long long ti[51];
long long ai[51];
long long bi[51];
long long res[50];

void cal(){
    for(int i = 2; i <= N; i++){
        if(ti[i] == 1){
            f_num[i] = (f_num[ai[i]] + f_num[bi[i]]) % 998244353;
        }
        else if(ti[i] == 2){
            f_num[i] = (ai[i] * f_num[bi[i]]) %  998244353;
        }
        else if(ti[i] == 3){
            f_num[i] = (f_num[ai[i]] * f_num[bi[i]]) % 998244353;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int testCase;
    // cin >> testCase;
    scanf("%d", &testCase);

    for(int t = 1; t <= testCase; t++){
        
        // cin >> N;
        scanf("%d", &N);
        
        for(int n = 2; n <= N; n++){
            // cin >> ti[n] >> ai[n] >> bi[n];
            scanf("%lld %lld %lld", &ti[n], &ai[n], &bi[n]);
        }
        
        //cin >> M;
        scanf("%d", &M);
        
        for(int i = 0; i < M; i++){
            f_num[0] = 1;
            // cin >> f_num[1];
            scanf("%lld", &f_num[1]);
            cal();
            res[i] = f_num[N];
        }
        
        // cout << "#" << t << " ";
        printf("#%d ", t);
        for(int i = 0; i < M; i++){
            // cout << res[i] << " ";
            printf("%lld ", res[i]);
        }
        // cout << endl;
        printf("\n");
    }
    
    return 0;
}
