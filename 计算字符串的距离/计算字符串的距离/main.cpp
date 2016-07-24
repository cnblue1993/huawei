//
//  main.cpp
//  计算字符串的距离
//
//  Created by anne on 16/7/10.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int calStringDistance (string s1, string  s2)
{
    int len1 = (int)s1.length();
    int len2 = (int)s2.length();
    if(len1==0)
        return len2;
    if(len2==0)
        return len1;
    
    vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
    
    for(int i = 0; i <= len1; i++)
        dp[i][0] = i;
    for(int j = 0; j <= len2; j++){
        dp[0][j] = j;
    }
    
    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = 1 + min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]);
            }
        }
    }
    return dp[len1][len2];
}

int main(int argc, const char * argv[]) {
    string s1,s2;
    while(cin>>s1>>s2){
        cout<<calStringDistance(s1, s2)<<endl;
    }
    return 0;
}
