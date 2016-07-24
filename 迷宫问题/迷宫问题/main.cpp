//
//  main.cpp
//  迷宫问题
//
//  Created by anne on 16/6/9.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void findWay(vector<vector<int>> maze, int n, int m){
    vector<vector<int>> dp(n, vector<int>(m,0));
    vector<int> x;
    vector<int> y;
    dp[0][0] = 1;
    
    //初始化dp
    for(int i = 1; i < m; i++){
        if(dp[0][i-1] && !maze[0][i])
            dp[0][i] = 1;
    }
    for(int i = 1; i < n; i++){
        if(dp[i-1][0] && !maze[i][0])
            dp[i][0] = 1;
    }
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if((dp[i][j-1] || dp[i-1][j]) && !maze[i][j])
                dp[i][j] = 1;
        }
    }

    
    x.push_back(n-1);
    y.push_back(m-1);
    for(int i = n-1, j = m-1; !(i == 0 && j == 0); ){
        if(j > 0 && dp[i][j-1] == 1){
            x.push_back(i);
            y.push_back(j-1);
            j--;
        }
        if(i > 0 && dp[i-1][j] == 1){
            x.push_back(i-1);
            y.push_back(j);
            i--;
        }
    }
    int num = (int)x.size();
    for(int i = num-1; i >= 0; i--){
        cout<<"("<<x[i]<<","<<y[i]<<")"<<endl;
    }
    
}

int main(int argc, const char * argv[]) {
    int n, m;
    while(cin>>n>>m){
        vector<vector<int>> maze(n, vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>maze[i][j];
            }
        }
        
        findWay(maze, n, m);
        
    }
    return 0;
}

/*
 6 5
 0 0 0 1 1
 1 1 0 1 1
 1 1 0 0 1
 1 1 1 0 1
 1 1 1 0 1
 1 1 1 0 0
 */
