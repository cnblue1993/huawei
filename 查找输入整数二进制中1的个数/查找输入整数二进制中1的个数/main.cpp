//
//  main.cpp
//  查找输入整数二进制中1的个数
//
//  Created by anne on 16/7/17.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>

using namespace std;

int findNumberOf1(int num){
    int sum = 0;
    while(num){
        sum++;
        num &= num - 1;
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    int num;
    while(cin>>num){
        cout<<findNumberOf1(num)<<endl;
    }
    return 0;
}
