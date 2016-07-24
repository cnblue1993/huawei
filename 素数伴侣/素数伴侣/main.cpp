//
//  main.cpp
//  素数伴侣
//
//  Created by anne on 16/5/23.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int n)
{
    int i;
    if(n<2)
    {
        return false;
    }
    for(i=2;i<=n/2;i++)
    {
        if(0==n%i)
        {
            return false;
        }
    }
    return true;
}

void findCouple(vector<int> num){
    int n = (int)num.size();
    vector<int> dp(n+1,0);
    for(int i = n-2; i >=0; i--){
        for(int j = n-1; j > i; j--){
            int temp = isPrime(num[i]+num[j]) ? dp[i+1] - dp[j-1] + dp[j+1] + 1 :dp[i+1];
            //总对数dp[i]=放入j之前的最大对数 + j和i之间的整数能组成的最大对数 + 1（即i和j组成的一对）=dp[j+1]+（dp[i+1]-dp[j-1]）+1
            dp[i] = max(temp,dp[i]);
        }
    }
    cout<<dp[0]<<endl;
}

int main(int argc, const char * argv[]) {
    int n;
    
    while(cin>>n){
        vector<int> num;
        int x;
        while(n--){
            cin>>x;
            num.push_back(x);
        }
        findCouple(num);
    }
    return 0;
}
