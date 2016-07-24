//
//  main.cpp
//  称砝码
//
//  Created by anne on 16/6/7.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void count(int n, vector<int> w, vector<int> m){
    int max = 0;
    for(int i = 0; i < n; i++){
        max += w[i] * m[i];
    }
    //cout<<max<<endl;
    
    vector<int> dp(max+1, 0);
    dp[0] = 1;
    
    for(int i = 0; i < n; i++){
        for(int j = max; j >= 0; j--){
            for(int k = 1; k <= m[i]; k++){
                if((j - k * w[i]) >= 0)
                    dp[j] = dp[j] | dp[j - k * w[i]];
            }
        }
    }
    int count = 0;
    for(int i = 0; i <= max ; i++)
        if(dp[i])
            count++;
    
    cout<<count<<endl;
}

int main(int argc, const char * argv[]) {
    int n;
    while(cin>>n){
        vector<int> weight(n,0);
        vector<int> num(n,0);
        
        for(int i = 0; i < n; i++)
            cin>>weight[i];
        
        for(int i = 0; i < n; i++)
            cin>>num[i];
        
        count(n, weight, num);
        
    }
    
    return 0;
}
