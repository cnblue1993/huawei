//
//  main.cpp
//  统计不同字符
//
//  Created by anne on 16/6/7.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void count(string str){
    int letter = 0;
    int num = 0;
    int space = 0;
    int character = 0;
    
    int len = (int)str.length();
    for (int i = 0; i < len; i++) {
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            letter++;
        else if(str[i] >= '0' && str[i] <= '9')
            num++;
        else if(str[i] == ' ')
            space++;
        else
            character++;
    }
    cout<<letter<<endl;
    cout<<space<<endl;
    cout<<num<<endl;
    cout<<character<<endl;
}

int main(int argc, const char * argv[]) {
    string str;
    while(getline(cin, str)){
        count(str);
    }
    return 0;
}
