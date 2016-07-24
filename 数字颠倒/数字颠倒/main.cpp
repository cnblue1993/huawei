//
//  main.cpp
//  数字颠倒
//
//  Created by anne on 16/5/5.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
//    int num;
//    while(cin>>num){
//        string result;
//        while(num > 0){
//            result.push_back((num % 10) + '0');
//            num /= 10;
//        }
//        cout<<result<<endl;
//    }
    string s;
    while(cin>>s){
        string result;
        int n = (int)s.length();
        for(int i = 0; i < n; i++){
            //result.push_back(s[i]);
            result = s[i] + result;
        }
        cout<<result<<endl;
    }
    return 0;
}
