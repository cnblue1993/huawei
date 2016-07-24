//
//  main.cpp
//  蛇形矩阵
//
//  Created by anne on 16/5/26.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void snackMatrix(int n){
    vector<vector<int>> result(n,vector<int>(n,0));
    int num = 1;
    for(int i = 0; i < n; i++){
        int k = i;
        for(int j = 0;k >= 0;){
            result[k--][j++] = num++;
        }
    }
    int row = (int)result.size();
    for(int i = 0; i < row; i++){
        for(int j = 0; j < n - i - 1;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<result[i][n - i - 1]<<endl;
    }
}

int main(int argc, const char * argv[]) {
    int n;
    while(cin>>n){
        snackMatrix(n);
    }
    return 0;
}
