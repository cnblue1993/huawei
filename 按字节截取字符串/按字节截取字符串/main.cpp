//
//  main.cpp
//  按字节截取字符串
//
//  Created by anne on 16/7/10.
//  Copyright © 2016年 anne. All rights reserved.
//

#include<iostream>
#include<string>
#include<stdio.h>
#include<string.h>

using namespace std;

const int len = 1001;

int main()
{
    char str[len];
    int n = 0;

    while(cin >> str >> n)
    {
        if(strlen(str) > n)
        {
            if(str[n-1] == '?')
                str[n-1] = '\0';
            else
                str[n] = '\0';
        }
        cout << str << endl;
    }
    return 0;
}
