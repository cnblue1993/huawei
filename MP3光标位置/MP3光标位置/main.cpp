//
//  main.cpp
//  MP3光标位置
//
//  Created by anne on 16/7/17.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void move(string command, int cur, int sum, int top, int buttom,int page){
    int len = (int)command.length();
    for(int i = 0; i < len; i++){
        if(command[i] == 'U'){
            if(cur == 1){
                cur = sum;
                buttom = sum;
                top = sum - (page-1);
            }
            else{
                cur--;
                if(cur >= top && cur<= buttom){
                    continue;
                }else{
                    top--;
                    buttom--;
                }
            }
        }else if(command[i] == 'D'){
            if(cur == sum){
                cur = 1;
                top = 1;
                buttom = page;
            }
            else{
                cur++;
                if(cur >= top && cur<= buttom){
                    continue;
                }else{
                    top++;
                    buttom++;
                }
            }
        }
    }
    for(int i = top; i < buttom; i++)
        cout<<i<<" ";
    cout<<buttom<<endl;
    cout<<cur<<endl;
}

int main(int argc, const char * argv[]) {
    int sum = 0;
    string command;
    while(cin>>sum>>command){
        int cur = 1;
        int top = 1;
        int buttom;
        if(sum < 4)
            buttom = sum;
        else
            buttom = 4;
        move(command, cur, sum, top, buttom, buttom);
    }
    return 0;
}
