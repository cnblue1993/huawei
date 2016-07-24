//
//  main.cpp
//  最长公共子串
//
//  Created by anne on 16/7/17.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void LCS(string s1, string s2){
    int len1 = (int) s1.length();
    int len2 = (int) s2.length();
    
    vector<vector<int>> dp(len1,vector<int>(len2,0));
    int index = 0;
    int max = 0;
    for(int i = 0; i < len1; i++){
        for(int j = 0; j < len2; j++){
            if(s1[i] == s2[j]){
                if(i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i-1][j-1] + 1;
            }
            if(dp[i][j] > max){
                max = dp[i][j];
                index = j;
            }
        }
    }
    cout<<s2.substr(index-max+1, max)<<endl;
}

int main(int argc, const char * argv[]) {
    string s1,s2;
    while(cin>>s1>>s2){
        LCS(s1, s2);
    }
    return 0;
}
