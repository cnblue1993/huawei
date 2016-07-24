//
//  main.cpp
//  字符串合并处理
//
//  Created by anne on 16/5/23.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

void init(map<char,char> &code){
    code.emplace('1','8');
    code.emplace('8','1');
    code.emplace('3','C');
    code.emplace('C','3');
    code.emplace('c','3');
    code.emplace('2','4');
    code.emplace('4','2');
    code.emplace('5','A');
    code.emplace('a','5');
    code.emplace('A','5');
    code.emplace('7','E');
    code.emplace('E','7');
    code.emplace('e','7');
    code.emplace('b','D');
    code.emplace('B','D');
    code.emplace('D','B');
    code.emplace('d','B');
    code.emplace('f','F');
}
void change(string s,map<char,char> map){
    int n = (int)s.length();
    for(int i = 0; i < n; i++){
        if(map.find(s[i])!=map.end())
            s[i] = map[s[i]];
    }
    cout<<s<<endl;
}

int main(int argc, const char * argv[]) {
    string s1,s2;
    map<char,char> code;
    init(code);
    while(cin>>s1>>s2){
        string s;
        s = s1 + s2;
        vector<char> odd,even;
        int n = (int)s.length();
        int flag = 0;
        if(n % 2 != 0){
            flag = -1;
        }
        for(int i = 0; i < n+flag; i=i+2){
            odd.push_back(s[i]);
            even.push_back(s[i+1]);
        }
        if(flag == -1)
            odd.push_back(s[n-1]);
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        int j = 0;
        for(int i = 0; i < n+flag; i=i+2){
            s[i] = odd[j];
            s[i+1] = even[j++];
        }
        if(flag == -1)
            s[n-1] = odd[j];
        change(s,code);
    }
    return 0;
}
