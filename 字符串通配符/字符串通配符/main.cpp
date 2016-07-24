//
//  main.cpp
//  字符串通配符
//
//  Created by anne on 16/7/18.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void match(string s1, string s2){
    int len = (int) s1.length();
    int i = 0;
    int j = 0;
    bool matched = false;
    while (i < len) {
        if(s1[i] == s2[j] || s1[i] == '?'){
            i++;
            j++;
        }else if(s1[i] == '*'){
            if(i == len -1){
                matched = true;
                break;
            }else if (i < len -1){
                while(s1[i++] != s2[j++]);
            }
        }else{
            matched = false;
            break;
        }
    }
    if(matched || j == s2.length())
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}


int main(int argc, const char * argv[]) {
    string s1,s2;
    while(cin>>s1>>s2){
        match(s1, s2);
    }
    return 0;
}
