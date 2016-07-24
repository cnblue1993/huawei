//
//  main.cpp
//  查找兄弟单词
//
//  Created by anne on 16/5/23.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

bool check(string str1, string str2){
    int len = (int)str1.length();
    map<char,int> s1;
    for(int i = 0; i < len; i++){
        if(s1.find(str1[i])!=s1.end())
            s1[str1[i]] += 1;
        else
            s1[str1[i]] = 1;
    }
    for(int i = 0; i < len; i++){
        if(s1.find(str2[i])==s1.end())
            return false;
        s1[str2[i]]--;
        if(s1[str2[i]] < 0)
            return false;
    }
    return true;
}

void findBorther(vector<string> dict, string target, int index){
    vector<string> borther;
    int len = (int)target.length();
    for(string s:dict){
        if(s.length() != len || s.compare(target) == 0)
            continue;
        if(check(target,s))
            borther.push_back(s);
    }
    sort(borther.begin(), borther.end());
    cout<<borther.size()<<endl;
    if(index <= borther.size())
        cout<<borther[index-1]<<endl;
}

int main(int argc, const char * argv[]) {
    int n;
    while(cin>>n){
        vector<string> dict;
        string str;
        while (n--) {
            cin>>str;
            dict.push_back(str);
        }
        string target;
        int index;
        cin>>target>>index;
        findBorther(dict,target,index);
    }
    return 0;
}
