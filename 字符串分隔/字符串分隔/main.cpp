//
//  main.cpp
//  字符串分隔
//
//  Created by anne on 16/5/4.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void fillString(string s){
    if(s.length() == 0)
        cout<<""<<endl;
    int length = (int)s.length();
    int n = length % 8 == 0 ? length : (length / 8 + 1) * 8;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(i < length){
            cout<<s[i];
            count++;
        }
        else{
            cout<<0;
            count++;
        }
        if(count == 8){
            count = 0;
            cout<<endl;
        }
        
    }
}

int main(int argc, const char * argv[]) {
    string s;
    while(cin>>s){
        fillString(s);
    }
    return 0;
}
