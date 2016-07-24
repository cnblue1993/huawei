//
//  main.cpp
//  密码验证合格程序
//
//  Created by anne on 16/5/7.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int LongChar(string str)
{
    int n = (int)str.length();
    if(n == 0)
        return 0;
    int max=0;
    int first=0;
    for(int i=1;i<n;i++)
        for(int k=0,j=0;j<n-i;j++)
        {
            if(str[j]==str[i+j])k++;
            else
                k=0;
            if(k>max)
            {
                max=k;
                first=j-k+1;
            }
        }
    return max;
}

int check4Type(string s){
    int n = (int)s.length();
    int A=0,a=0,num=0,sign=0;
    for(int i = 0; i < n;i++){
        if(s[i]>='A' && s[i]<='Z')
            A=1;
        else if(s[i]>='a' && s[i]<='z')
            a=1;
        else if(s[i]>='0' && s[i]<='9')
            num=1;
        else
            sign=1;
        if(a+A+num+sign>=3)
            break;
    }
    return a+A+num+sign;
}

int main(int argc, const char * argv[]) {
    string s;
    while(getline(cin,s)){
        if(check4Type(s)<3 || s.length() <= 8)
            cout<<"NG"<<endl;
        else{
            if(LongChar(s)>2)
                cout<<"NG"<<endl;
            else
                cout<<"OK"<<endl;
        }
    }
    return 0;
}
