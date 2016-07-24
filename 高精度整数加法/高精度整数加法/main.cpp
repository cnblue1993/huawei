//
//  main.cpp
//  高精度整数加法
//
//  Created by anne on 16/7/10.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void strToNum(string s1, string s2, vector<int> &num1, vector<int> &num2){
    int len1 =(int) s1.length();
    int len2 = (int) s2.length();
    for (int i = 0; i < len1; i++) {
        num1[i] = s1[len1 - i -1] - '0';
    }
    for (int i = 0; i < len2; i++) {
        num2[i] = s2[len2 - i -1] - '0';
    }
}

void add(vector<int> num1, vector<int> num2, vector<int> &result){
    int len = num1.size() >= num2.size() ? (int)num1.size(): (int)num2.size();
    int carry = 0;
    int i;
    for(i = 0; i < len; i++){
        result[i] = (num1[i] + num2[i] + carry) % 10;
        carry = (num1[i] + num2[i] + carry) / 10;
    }
    if(carry > 0){
        result[i] = 1;
    }
}

void sub(vector<int> num1, vector<int> num2, vector<int> &result){
    int carry = 0;
    int len = (int)num1.size();
    int i;
    for(i = 0; i < len; i++){
        if((num1[i] + carry) < num2[i]){
            result[i] = 10 + num1[i] - num2[i] + carry;
            carry = -1;
        }else{
            result[i] = num1[i] - num2[i];
            carry = 0;
        }
    }
}


int main(int argc, const char * argv[]) {
    string str1,str2;
    while(cin>>str1>>str2){
        char symbol;
        int len = str1.length() >= str2.length() ? (int)str1.length() : (int)str2.length();
        vector<int> num1(len,0);
        vector<int> num2(len,0);
        vector<int> result(len+1,0);
        if(str1[0] == '-' && str2[0] == '-'){
            symbol = '-';
            strToNum(str1.substr(1,str1.length()),str2.substr(1,str2.length()), num1,num2);
            add(num1, num2, result);
        }
        else if (str1[0] == '-' || str2[0] == '-'){
            if(str1[0] == '-'){
                strToNum(str1.substr(1,str1.length()),str2, num1,num2);
                if(str1.substr(1,str1.length()).compare(str2)<0){
                    sub(num2,num1,result);
                    symbol = '+';
                }else{
                    sub(num1,num2,result);
                    symbol = '-';
                }
            }else{
                strToNum(str1,str2.substr(1,str2.length()), num1,num2);
                if(str2.substr(1,str2.length()).compare(str1)<0){
                    sub(num1,num2,result);
                    symbol = '+';
                }else{
                    sub(num2,num1,result);
                    symbol = '-';
                }
 
            }
            
        }else{
            symbol = '+';
            strToNum(str1, str2, num1, num2);
            add(num1, num2, result);
        }
        if(symbol == '-'){
            cout<<"-";
        }
        int i = len;
        while(result[i] == 0){
            i--;
        }
        for(;i >=0; i--)
            cout<<result[i];
        cout<<endl;
    }
    return 0;
}
