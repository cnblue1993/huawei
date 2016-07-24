//
//  main.cpp
//  字符串加解密
//
//  Created by anne on 16/5/23.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void encode(string s){
    int len = (int)s.length();
    for(int i = 0; i < len; i++){
        if(s[i] == 'z')
            s[i] =  'A';
        else if(s[i] == 'Z')
            s[i] = 'a';
        else if(s[i] == '9')
            s[i] = '0';
        else if(s[i] >= 'a' && s[i] <'z'){
            s[i] = (s[i] + 1) - 32;
        }else if(s[i] >= 'A' && s[i] < 'Z'){
            s[i] = (s[i] + 1) + 32;
        }else if (s[i] >= '0' && s[i] < '9'){
            s[i]++;
        }else{
            continue;
        }
    }
    cout<<s<<endl;
}

void decode(string s){
    int len = (int)s.length();
    for(int i = 0; i < len; i++){
        if(s[i] == 'A')
            s[i] = 'z';
        else if(s[i] == 'a')
            s[i] = 'Z';
        else if(s[i] == '0')
            s[i] = '9';
        else if(s[i] > 'a' && s[i] <='z'){
            s[i] = (s[i] - 1) - 32;
        }else if(s[i] > 'A' && s[i] <= 'Z'){
            s[i] = (s[i] - 1) + 32;
        }else if (s[i] > '0' && s[i] <= '9'){
            s[i]--;
        }else{
            continue;
        }
    }
    cout<<s<<endl;
}

int main(int argc, const char * argv[]) {

    string s1,s2;
    while (cin>>s1>>s2) {
        encode(s1);
        decode(s2);
    }
    return 0;
}
