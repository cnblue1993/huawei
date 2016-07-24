//
//  main.cpp
//  进制转换
//
//  Created by anne on 16/5/9.
//  Copyright © 2016年 anne. All rights reserved.
//

//样例输入:
//291,2
//样例输出:
//100100011

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    int num,n;
    char c;
    while(cin>>num>>c>>n){
        vector<int> result;
        if(n<2||n>9)
            break;
        while(num){
            result.push_back(num % n);
            num /= n;
        }
        int len = (int)result.size();
        for(int i = len - 1; i >= 0; i--)
            cout<<result[i];
        cout<<endl;
    }
    return 0;
}
