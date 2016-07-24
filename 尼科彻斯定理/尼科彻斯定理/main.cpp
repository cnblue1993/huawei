//
//  main.cpp
//  尼科彻斯定理
//
//  Created by anne on 16/7/18.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

//string intTostring(int n){
//    string temp = "";
//    char c[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
//    while(n){
//        temp = c[n%10] + temp;
//        n /= 10;
//    }
//    return temp;
//}

void GetSequeOddNum(int num){
    string temp = "";
    int n = num * (num - 1) + 1;
    for(int i = 1; i < num; i++,n += 2){
        temp = temp + to_string(n)+ "+";
    }
    temp = temp + to_string(n);
    cout<<temp<<endl;
}

int main(int argc, const char * argv[]) {
    int num;
    while(cin>>num){
        GetSequeOddNum(num);
    }
    return 0;
}
