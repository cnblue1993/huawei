//
//  main.cpp
//  矩阵乘法计算量估算
//
//  Created by anne on 16/7/17.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

void calculate(vector<vector<int>> matrix, string str){
    stack<int> num;
    stack<char> balance;
    int len = (int)str.length();
    int index = 0;
    int result = 0;
    
    for(int i = 0; i < len; i++){
        if(str[i] == '('){
            
        }
        else if (str[i] == ')'){
            if(num.size() >=4){
                int col = num.top();
                num.pop();
                int temp = col * num.top();
                num.pop();
                num.pop();
                int row= num.top();
                temp *= row;
                num.pop();
                result += temp;
                
                num.push(row);
                num.push(col);
            }
        }else{
            num.push(matrix[index][0]);
            num.push(matrix[index++][1]);
        }
    }
    cout<<result<<endl;
}

int main(int argc, const char * argv[]) {
    int n;
    while(cin>>n){
        vector<vector<int>> matrix(n,vector<int>(2));
        string str;
        for(int i = 0; i < n; i++)
            cin>>matrix[i][0]>>matrix[i][1];
        cin>>str;
        calculate(matrix, str);
    }
    return 0;
}
