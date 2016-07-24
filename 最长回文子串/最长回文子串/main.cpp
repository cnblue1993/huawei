//
//  main.cpp
//  最长回文子串
//
//  Created by anne on 16/5/24.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void longestPalindrome(string s){
    int len = (int)s.length();
    int maxlen = 1,begin = 0;
    vector<vector<bool>> dp(len,vector<bool>(len,false));
    
    for(int i = 0; i < len; i++)
        dp[i][i] = true;
    
    for(int i = 0; i < len-1; i++){
        if(s[i] == s[i+1]){
            dp[i][i+1] = true;
            begin = i;
            maxlen = 2;
        }
    }
    for(int i = len - 3; i >= 0; i--){
        for(int j = i + 2; j < len; j++){
            if(s[i] == s[j] && dp[i+1][j-1]){
                dp[i][j] = true;
                if(maxlen < j-i+1){
                    begin=i;
                    maxlen=j-i+1;
                }
            }
        }
    }
    cout<<maxlen<<endl;
    
    
}

int main(int argc, const char * argv[]) {
    string s;
    while(cin>>s){
        longestPalindrome(s);
    }
    return 0;
}
