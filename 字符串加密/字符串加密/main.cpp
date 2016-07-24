//
//  main.cpp
//  字符串加密
//
//  Created by anne on 16/5/26.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void encode(string key, string code){
    int n = (int)key.length();
    vector<char> result(26);
    vector<bool> letter(26,true);
    int j = 0;
    int index;
    
    for(int i = 0; i < n; i++){
        if(key[i] >= 'a' && key[i] <= 'z'){
            index = key[i] - 'a';
        }else{
            index = key[i] - 'A';
        }
        if(letter[index]){
            result[j++] = key[i];
            letter[index] = false;
        }
    }
    for(int i = 0; i < 26; i++){
        if(letter[i]){
            result[j++] = i + 'a';
            letter[i] = false;
        }
        //cout<<result[i]<<" ";
    }
    
    n = (int)code.length();
    for(int i = 0; i < n; i++){
        if(code[i] >= 'a' && code[i] <= 'z'){
            index = code[i] - 'a';
            code[i] = result[index];
        }else{
            index = code[i] - 'A';
            code[i] = result[index] - 32;
        }
    }
    cout<<code<<endl;
}

int main(int argc, const char * argv[]) {
    string key,code;
    while(cin>>key>>code){
        encode(key,code);
    }
    return 0;
}
