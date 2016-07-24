//
//  main.cpp
//  简单密码
//
//  Created by anne on 16/5/7.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

void initMap(map<char,char> &m){
    m.emplace('a','2');
    m.emplace('b','2');
    m.emplace('c','2');
    m.emplace('d','3');
    m.emplace('e','3');
    m.emplace('f','3');
    m.emplace('g','4');
    m.emplace('h','4');
    m.emplace('i','4');
    m.emplace('j','5');
    m.emplace('k','5');
    m.emplace('l','5');
    m.emplace('m','6');
    m.emplace('n','6');
    m.emplace('o','6');
    m.emplace('p','7');
    m.emplace('q','7');
    m.emplace('r','7');
    m.emplace('s','7');
    m.emplace('t','8');
    m.emplace('u','8');
    m.emplace('v','8');
    m.emplace('w','9');
    m.emplace('x','9');
    m.emplace('y','9');
    m.emplace('z','9');
}

int main(int argc, const char * argv[]) {
    string s;
    map<char,char> m;
    initMap(m);
    while(cin>>s){
        int n = (int)s.length();
        for(int i = 0; i < n; i++){
            if(s[i]>='A' && s[i]<'Z'){
                s[i] += 33;
            }else if(s[i] == 'Z')
                s[i] = 'a';
            else if(s[i]>='a' && s[i]<='z')
                s[i] = m[s[i]];
        }
        cout<<s<<endl;
    }
    return 0;
}
