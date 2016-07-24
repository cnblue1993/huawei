//
//  main.cpp
//  句子逆序
//
//  Created by anne on 16/5/5.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    string s;
    while(getline(cin,s)){
        int n = (int)s.length();
        string result,temp;
        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                result =" " + temp + result;
                temp = "";
            }else{
                temp += s[i];
            }
        }
        result = temp + result;
        cout<<result<<endl;
    }
    return 0;
}
