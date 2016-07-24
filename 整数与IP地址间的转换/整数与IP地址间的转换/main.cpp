//
//  main.cpp
//  整数与IP地址间的转换
//
//  Created by anne on 16/5/24.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

void IPToInt(string ip){
    int len = (int)ip.length();
    int value = 0;
    vector<int> values;
    
    for(int i = 0; i < len; i++){
        if(ip[i] >= '0' && ip[i] <= '9'){
            value = value * 10 + (ip[i] - '0');
        }
        else{
            values.push_back(value);
            value = 0;
        }
    }
    values.push_back(value);
    
    string binary = "";
    for(int i = 3; i >= 0 ;i--){
        int j = 0;
        while(values[i]){
            char temp = (values[i] % 2) + '0';
            binary = temp + binary;
            values[i] /= 2;
            j++;
        }
        j = 8 - j;
        while(j--){
            binary = '0' + binary;
        }
    }
    
    int n = (int)binary.length();
    long result = 0;
    int j = 0;
    for(int i = n-1; i >= 0; i--){
        result += (binary[i] - '0')*pow(2,j);
        j++;
    }
    
    cout<<result<<endl;
}

void IntToIP(long dex){
    string ip = "";
    while(dex){
        char temp = dex % 2 + '0';
        ip = temp + ip;
        dex /= 2;
    }
    int n = 32 - (int)ip.length();
    while(n--){
        ip = '0' + ip;
    }
    
    vector<int> values;
    int value = 0;
   
    for(int i = 1; i <= 4; i++){
        int j = i * 8;
        value = 0;
        for(j = j-1; j >= (i-1) * 8; j--){
            value += (ip[j] - '0') * pow(2,i * 8-1-j);
            //cout<<(ip[i] - '0') << pow(2,i * 8-1-j)<<endl;
        }
        values.push_back(value);
    }
    for(int i = 0; i < 4; i++){
        string temp = "";
        while(values[i]){
            temp = (char)(values[i] % 10 + '0') + temp;
            values[i] /= 10;
        }
        if(i == 3)
            cout<<temp<<endl;
        else
            cout<<temp<<".";
    }
}

int main(int argc, const char * argv[]) {
    string ip;
    long dex;
    while(cin>>ip>>dex){
        IPToInt(ip);
        IntToIP(dex);
    }
    return 0;
}
