//
//  main.cpp
//  输入法查找
//
//  Created by anne on 16/5/9.
//  Copyright © 2016年 anne. All rights reserved.
//

/*
 Code
 AA_a
 AI_ai
 XI_xi
 XI1_xi
 XI2_xi
 Search
 xi
 End
 样例输出:
 XI;XI1;XI2
 */

#include <iostream>
#include <map>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

void buildDic(map<string, string> &dic,string word){
    string key,value;
    int len = (int)word.size();
    int flag = false;
    for(int i = 0; i < len; i++){
        if(word[i] == '_'){
            flag = true;
            continue;
        }
        if(flag){
            value.push_back(word[i]);
        }else{
            key.push_back(word[i]);
        }
    }
    dic.emplace(key,value);
}
void searchWord(map<string, string> &dic,string word,vector<string> &result){
    string target;
    int index = 0, j = 0;
    bool flag = false;
    for (int i = 0; i < word.length(); i++){
        if(word[i]>= '0' && word[i]<= '9'){
            flag = true;
            index += (word[i] - '0') * pow(10,j++);
        }else
            target.push_back(word[i]);
    }
    for(auto x : dic){
        if(x.second.compare(target) == 0)
            result.push_back(x.first);
    }
    //处理有序号
    if(flag){
        string temp;
        if(index <= result.size()){
            temp = result[index - 1];
            result.clear();
            result.push_back(temp);
        }else{
            result.clear();
        }
        
    }
}

int main(int argc, const char * argv[]) {
    string cmd,word;
    bool code = false, search = false , end = false;
    
    map<string, string> dic;
    vector<string> result;
    
    while(cin>>cmd){
        
        if(cmd == "Code"){
            code = true;
        }else if(cmd == "Search"){
            search = true;
            code = false;
        }else if(cmd == "End"){
            break;
        }
        
        if(code){
            while(cin>>word && code){
                if(word.compare("Search") == 0){
                    search = true;
                    code = false;
                    break;
                }else{
                    buildDic(dic,word);
                }
            }
        }
        if(search){
            while(cin>>word && search){
                if(word == "End"){
                    search = false;
                    end = true;
                    break;
                }else{
                    searchWord(dic,word,result);
                }
            }
        }
        if(end)
            break;
    }
    if(result.size() == 0)
        cout<<"Error"<<endl;
    else{
        int i = 0, count = 0;
        for(; i < result.size() -1 && count < 4; i++){
            cout<<result[i]<<";";
            count++;
        }
        cout<<result[i]<<endl;
    }
    return 0;
}
