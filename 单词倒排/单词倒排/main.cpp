//
//  main.cpp
//  单词倒排
//
//  Created by anne on 16/5/24.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reverseSentence(string s){
    int len = (int)s.length();
    vector<string> words;
    string word = "";
    for(int i = 0; i < len; i++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            word = word + s[i];
        }
        else{
            if(word.length() != 0){
                words.push_back(word);
            }
            word = "";
        }
    }
    if(word.length() != 0){
        words.push_back(word);
    }
    int n = (int)words.size();
    for(int i = n-1; i > 0; i--){
        cout<<words[i]<<" ";
    }
    cout<<words[0]<<endl;
}

int main(int argc, const char * argv[]) {
    string s;
    while(getline(cin, s)){
        reverseSentence(s);
    }
    return 0;
}
