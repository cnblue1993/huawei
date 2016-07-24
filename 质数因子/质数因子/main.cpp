//
//  main.cpp
//  质数因子
//
//  Created by anne on 16/5/4.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string change(long num){
    string s;
    for(int i = 0; num > 0; i++){
        int t = num % 10;
        s.push_back(t + '0');
        num /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}
string getResult(long ulDataInput){
    string s;
    for(long i = 2; ulDataInput>1;){
        if(ulDataInput % i == 0)
        {
            string c = change(i);
            s = s + c;
            s.push_back(' ');
            ulDataInput /= i;
        }else{
            i++;
        }
    }
    return s;
}

int main(int argc, const char * argv[]) {
    long ulDataInput;
    while(cin>>ulDataInput){
        cout<<getResult(ulDataInput)<<endl;
//        string s = getResult(ulDataInput);
//        int n = (int)s.length();
//        for(int i = 0; i < n; i++)
//            cout<<s[i];
//        cout<<endl;
    }
    return 0;
}
