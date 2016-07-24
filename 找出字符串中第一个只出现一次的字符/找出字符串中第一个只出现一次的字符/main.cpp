//
//  main.cpp
//  找出字符串中第一个只出现一次的字符
//
//  Created by anne on 16/7/10.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void onlyOne(string s){
    vector<int> index(26,-1);
    int len = (int)s.length();
    for(int i = 0; i < len; i++){
        if(index[s[i] - 'a'] == -1)
            index[s[i] - 'a']= i;
        else
            index[s[i] - 'a'] = -2;
    }
    sort(index.begin(), index.end());
    int i = 0;
    while(index[i] == -1 || index[i] == -2){
        i++;
    }
    if(i == 26)
        cout<<'.'<<endl;
    else
        cout<<s[index[i]]<<endl;
}


int main(int argc, const char * argv[]) {
    string str;
    while(cin>>str){
        onlyOne(str);
    }
    return 0;
}
