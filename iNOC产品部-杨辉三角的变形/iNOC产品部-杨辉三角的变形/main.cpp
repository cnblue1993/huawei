//
//  main.cpp
//  iNOC产品部-杨辉三角的变形
//
//  Created by anne on 16/7/10.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int triangle(int n){
    vector<vector<int>> dp(n,vector<int>(n,0));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0)
                dp[i][j] = 1;
            else if (j == 1)
                dp[i][j] = dp[i-1][j] + 1;
            else if (i == j)
                dp[i][j] = 2 * dp[i-1][j-2] + dp[i-1][j-1];
            else
                dp[i][j] = dp[i-1][j-2] + dp[i-1][j-1] + dp[i-1][j];
            if(i == n-1 && dp[i][j] % 2 == 0)
                return j+1;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int n;
    while(cin>>n){
        cout<<triangle(n)<<endl;
    }
    return 0;
}
