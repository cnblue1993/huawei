//
//  main.cpp
//  图片整理
//
//  Created by anne on 16/5/26.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(int argc, const char * argv[]) {
    string files;
    while(cin>>files){
        sort(files.begin(),files.end());
        cout<<files<<endl;
    }
    return 0;
}

/*
 #include<stdio.h>
 #include<string.h>
 int main()
 {
 char str[1025];
 int len = 0;
 int min = 0;
 int temp = 0;
 while(gets(str) != NULL)
 {
 len = strlen(str);
 for(int i=0; i<len; i++)
 {
 min = i;
 for(int j=i+1; j<len; j++)
 {
 if(str[min] > str[j])
 min = j;
 }
 if(i != min)
 {
 temp = str[i];
 str[i] = str[min];
 str[min] = temp;
 }
 }
 for(int k=0; k<len; k++)
 {
 printf("%c",str[k]);
 }
 printf("\n");
 }
 return 0;
 }
*/