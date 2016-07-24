//
//  main.cpp
//  参数解析
//
//  Created by anne on 16/7/18.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void analyze(string s){
    int len = (int) s.length();
    bool flag = true;
    vector<string> result;
    string temp = "";
    for(int i = 0; i < len; i++){
        if(s[i] == ' ' && flag){
            result.push_back(temp);
            temp = "";
        }else if (s[i] == '"'){
            flag = !flag;
        }else{
            temp = temp + s[i];
        }
    }
    if(temp.length() != 0)
        result.push_back(temp);
    cout<<result.size()<<endl;
    for(string x : result){
        cout<<x<<endl;
    }
}

int main(int argc, const char * argv[]) {
    string s;
    while(getline(cin, s)){
        analyze(s);
    }
    return 0;
}
