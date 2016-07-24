//
//  main.cpp
//  坐标移动
//
//  Created by anne on 16/5/6.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int isValid(string s){
    int n = (int)s.length();
    if(n <= 1 || n > 3)
        return 0;
    int result = 0;
    for(int i = 0; i < n; i++){
        if(i == 0){
            if(!(s[i]=='A' || s[i]=='D' || s[i]=='W' || s[i]=='S'))
                return 0;
        }else{
            if (!(s[i] >= '0' && s[i] <= '9')) {
                return 0;
            }
            result += (s[i]-'0') * pow(10,n-1-i);
        }
    }
    cout<<result<<endl;
    return result;
}
void calculate(string s){
    string temp;
    int n = (int)s.length();
    int x = 0;
    int y = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == ';'){
            int result = isValid(temp);
            if(result){
                if(temp[0] == 'A')
                    x -= result;
                else if(temp[0] == 'D')
                    x += result;
                else if(temp[0] == 'W')
                    y += result;
                else
                    y -= result;
            }
            temp = "";
        }else{
            temp +=s[i];
        }
    }
    
    cout<<x<<","<<y<<endl;
}

int main(int argc, const char * argv[]) {
    string s;
    while(getline(cin,s)){
        calculate(s);
    }
    return 0;
}
