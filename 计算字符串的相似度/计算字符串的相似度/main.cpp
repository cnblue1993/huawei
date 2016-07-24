//
//  main.cpp
//  计算字符串的相似度
//
//  Created by anne on 16/7/18.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void calculateStringDistance(string s1, string s2){
    int len1 = (int) s1.length();
    int len2 = (int) s2.length();
    if(len1 == 0 && len2 == 0){
        cout<<1<<endl;
        return;
    }
    else if(len1 == 0){
        cout<<"1/"<<len2+1<<endl;
        return;
    }else if(len2 == 0){
        cout<<"1/"<<len1+1<<endl;
        return;
    }
    
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    
    for(int i = 0; i <= len2; i++){
        dp[0][i] = i;
    }
    for(int i = 0; i <= len1; i++){
        dp[i][0] = i;
    }
    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
            }
        }
    }
    cout<<"1/"<<dp[len1][len2] + 1<<endl;
    
}

int main(int argc, const char * argv[]) {
    string s1, s2;
    
    while(cin>>s1>>s2){
        calculateStringDistance(s1,s2);
    }
    return 0;
}
