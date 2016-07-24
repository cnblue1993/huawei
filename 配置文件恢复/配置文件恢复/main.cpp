//
//  main.cpp
//  配置文件恢复
//
//  Created by anne on 16/7/17.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int findCommand(string command, string first[], string second[]){
    string s1="",s2="";
    vector<int> result;
    int len = (int) command.length();
    int flag = true;
    for(int i = 0; i < len; i++){
        if(command[i] == ' '){
            flag = false;
            continue;
        }
        if(flag)
            s1 = s1 + command[i];
        else
            s2 = s2 + command[i];
    }

    if(s2.length() == 0){
        for(int i = 0; i <s1.length(); i++){
            if(s1[i] != first[0][i])
                return -1;
        }
        return 0;
    }else{
        for(int i = 1; i < 6; i++){
            bool flag = true;
            for(int j = 0; j < s1.length(); j++){
                if(s1[j] != first[i][j])
                    flag = false;
            }
            for(int j = 0; j < s2.length() && flag; j++){
                if(s2[j] != second[i][j])
                    flag = false;
            }
            if(flag)
                result.push_back(i);
        }
    }
    if(result.size() == 1)
        return result[0];
    else
        return -1;
}

int main(int argc, const char * argv[]) {
    string command;
    string first[6] = {"reset", "reset", "board", "board","reboot","backplane"};
    string second[6] = {"", "board", "add", "delet", "backplane", "abort"};
    string result[6] = {"reset what", "board fault", "where to add", "no board at all", "impossible", "install first"};
    while(getline(cin, command)){
        int res = findCommand(command, first, second);
        if(res == -1)
            cout<<"unkown command"<<endl;
        else
            cout<<result[res]<<endl;
    }
    return 0;
}


