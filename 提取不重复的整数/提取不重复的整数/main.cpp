//
//  main.cpp
//  提取不重复的整数
//
//  Created by anne on 16/5/5.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
//    long num;
//    while(cin>>num){
//        long result=0;
//        vector<bool> flag(10,false);
//        vector<int> temp;
//        while(num>0){
//            if(!flag[num % 10]){
//                temp.push_back(num % 10);
//                flag[num % 10] = true;
//            }
//            num /=10;
//        }
//        int n =(int)temp.size(),j=0;
//        for(int i = n-1; i >= 0; i--){
//            result += pow(10, j) * temp[i];
//            j++;
//        }
//        cout<<result<<endl;
//    }
    string s;
    while(cin>>s){
        int n = (int)s.length();
        int count = 0;
        vector<bool> flag(128,false);
        for(int i = 0; i < n; i++){
            if(s[i] >= 0 && s[i] < 128){
                if(!flag[s[i]]){
                    count++;
                    flag[s[i]] = true;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
