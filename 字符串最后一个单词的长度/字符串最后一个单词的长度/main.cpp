//
//  main.cpp
//  字符串最后一个单词的长度
//
//  Created by anne on 16/5/4.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int lastWordLength(string s){
    int curLen = 0;
    for(int i = 0; s[i] != '\0'; i++){
        
        if(s[i] != ' ')
            curLen++;
        else
            curLen = 0;
    }
    return curLen;
}

int main(int argc, const char * argv[]) {
    string s;
    getline(cin,s);  // 不能用cin输入，cin不能输入空格
    cout<<lastWordLength(s)<<endl;
    return 0;
}
