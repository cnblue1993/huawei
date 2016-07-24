//
//  main.cpp
//  计算字符个数
//
//  Created by anne on 16/5/4.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int count(string s, char t){
    int result = 0;
    if(t >='A' && t <='Z')
        t += 32;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] >='A' && s[i] <='Z')
            s[i] += 32;
        if(s[i] == t)
            result++;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    string s;
    char t;
    getline(cin, s);
    cin>>t;
    cout<<count(s,t)<<endl;
    return 0;
}
