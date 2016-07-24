//
//  main.cpp
//  矩阵乘法
//
//  Created by anne on 16/7/17.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int multiply(vector<vector<int>> arr1, vector<vector<int>> arr2, int row, int col){
    int result = 0;
    for(int i = 0; i < arr1[row].size(); i++){
        result += arr1[row][i] * arr2[i][col];
    }
    return result;
}

void print_matrix(vector<vector<int>> arr3, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col-1; j++){
            cout<<arr3[i][j]<<" ";
        }
        cout<<arr3[i][col-1]<<endl;
    }
}

void matrix_multiply(vector<vector<int>> arr1, vector<vector<int>> arr2, int x, int y, int z){
    vector<vector<int>> arr3(x, vector<int> (z));
    for(int i = 0; i < x; i++){
        for(int j = 0; j < z; j++){
            arr3[i][j] = multiply(arr1, arr2, i, j);
        }
    }
    print_matrix(arr3, x, z);
}

int main(int argc, const char * argv[]) {
    int x, y, z;
    while(cin>>x>>y>>z){
        vector<vector<int>> arr1(x,vector<int>(y));
        vector<vector<int>> arr2(y,vector<int>(z));
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                cin>>arr1[i][j];
            }
        }
        for(int i = 0; i < y; i++){
            for(int j = 0; j < z; j++){
                cin>>arr2[i][j];
            }
        }
        matrix_multiply(arr1, arr2, x, y, z);
    }
    return 0;
}
