//
//  main.cpp
//  删除字符串中出现次数最少的字符
//
//  Created by anne on 16/5/7.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;


int main(int argc, const char * argv[]) {
    string s;
    
    while(cin>>s){
        map<char,int> m;
        int n = (int)s.length();
        int minLen = 20;
        for(int i = 0; i < n; i++){
            if(m.find(s[i])!= m.end()){
                m[s[i]]++;
            }else
                m[s[i]]=1;
            if(minLen > m[s[i]])
                minLen = m[s[i]];
        }
        for(int i = 0; i < n; i++){
            if(m[s[i]] == minLen){
                s.erase(s.begin() + i);
                i--;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
