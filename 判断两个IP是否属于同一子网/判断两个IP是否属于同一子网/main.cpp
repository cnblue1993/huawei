//
//  main.cpp
//  判断两个IP是否属于同一子网
//
//  Created by anne on 16/5/26.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void changeToDex(string str, vector<int> &num, bool &flag){
    int len = (int)str.length();
    int temp = 0;
    int k = 0;
    for(int i = 0; i < len; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            temp = temp * 10 + (str[i] - '0');
        }else if(str[i] == '.'){
            k++;
            if(k>4){
                flag = false;
                break;
            }
            else{
                num.push_back(temp);
                temp = 0;
            }
        }else{
            flag = false;
            break;
        }
    }
    if(k==3){
        num.push_back(temp);
    }
    
}

bool isLowFullOne(int n){
    if(n == 0)
        return false;
    if((n & (n+1)) == 0)
        return true;
    else
        return false;
}

bool isContinuousOne(int n){
    while(n){
        if((n & 1) == 0)
            n = n>>1;
        else
            break;
    }
    return (n & (n+1)) == 0 ? true : false;
}

bool isMask(vector<int> mask){
    bool flag = false;
    for(int i = 3; i >=0; i--){
        if(flag){
            if(!isLowFullOne(mask[i]) && mask[i] != 255){
                return false;
            }
        }
        if(mask[i] != 0){
            flag = 1;
            if(i != 3){
                if(!isContinuousOne(mask[i]))
                    return false;
            }else{
                if(!isContinuousOne(mask[i]))
                    return false;
                if(isLowFullOne(mask[i]))
                    return false;
            }
        }
    }
    if(mask[0] == 255 && mask[1] == 255 && mask[2] == 255 &&mask[3] == 255)
        return false;
    else
        return true;
}

bool isAddr(vector<int> ip){
    for(int i = 0; i < 4; i++){
        if(ip[i] > 255 || ip[i] < 0)
            return false;
    }
    return true;
}

bool checkNetSegment(vector<int> mask, vector<int> ip1, vector<int> ip2){
    for(int i = 0; i < 4; i++){
        if((mask[i] & ip1[i]) != (mask[i] & ip2[i])){
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    string maskStr,ip1Str,ip2Str;
    vector<int> mask,ip1,ip2;
    bool flag = true;
    while(cin>>maskStr>>ip1Str>>ip2Str){
        changeToDex(maskStr, mask, flag);
        changeToDex(ip1Str, ip1, flag);
        changeToDex(ip2Str, ip2, flag);

        if(!(isMask(mask) && isAddr(ip1) && isAddr(ip2) && flag)){
            cout<<"1"<<endl;
        }else{
            if(checkNetSegment(mask, ip1, ip2))
                cout<<"0"<<endl;
            else
                cout<<"2"<<endl;
        }
    }
    return 0;
}

/*
 #include<stdio.h>
 #include<string.h>
 int main(void)
 {
     int ipcode[3][4]={0};
     int temp = 0 ;
     char data[20];
     char fifo[4];
     int num = 0;
     int num1 = 0;
     int num2 = 0;
     int flag = 0;
     int len;
     int seq1[4];
     int seq2[4];
     while(gets(data)!=NULL)
     {
         len = strlen(data);
         for(num = 0;num<len;num++)
         {
             if(data[num] != '.')
             {
                temp = temp*10+ (data[num]-'0');
                ipcode[num1][num2] =  temp;
             }
             else
             {
                temp = 0;
                num2 ++;
             }
        }
         num1++;
         num2= 0;
         temp = 0;
         if(num1==3)
         {
             
             for(num = 0;num<4;num++)
             {
                seq1[num] =  ipcode[0][num] & ipcode[1][num];
                seq2[num] =  ipcode[0][num] & ipcode[2][num];
             }
             
             if(seq1[0]==seq2[0]&&seq1[1]==seq2[1]&&seq1[2]==seq2[2]&&seq1[3]==seq2[3])
             {
                printf("0\n");
             }
             else
             {
                printf("2\n");
             }
             temp = 0 ;
             num = 0;
             num1 = 0;
             num2 = 0;
             flag = 0;
         }
     }
     return 0;
 }
 */
