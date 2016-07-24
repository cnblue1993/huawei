//
//  main.cpp
//  学英语
//
//  Created by anne on 16/6/7.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


int main(int argc, const char * argv[]) {
    long num;
    while (cin>>num) {
        vector<int> arr;
        
        while(num){
            arr.push_back(num % 10);
            num /= 10;
        }
        
        int n = (int)arr.size();
        string str = "";
        
        vector<string> a1 = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        vector<string> a2 = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
        vector<string> a3 = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
        
        for(int i = n-1; i >= 0;){
            if(i == 9){
                str =str + a1[arr[i]] + " billion ";
                i--;
                
            }else if (i == 8 || i == 5 || i == 2){
                str = str + a1[arr[i]] + " hundred and ";
                if(arr[i-1] == 1){
                    str = str + a2[arr[i-2]];
                }else{
                    str = str + a3[arr[i-1]] + " " + a1[arr[i-2]];
                }
                if(i == 8)
                    str = str + " million ";
                else if(i == 5)
                    str = str + " thousand ";
                i = i - 3;
                
            }else if (i == 7 || i == 4 || i == 1){
                if(arr[i] == 1){
                    str = str + a2[arr[i]];
                }else{
                    str = str + a3[arr[i]] + " " + a1[arr[i-1]];
                }
                if(i == 7)
                    str = str + " million ";
                else if(i == 4)
                    str = str + " thousand ";
                i = i - 2;
            }else if(i == 3){
                str = str + a1[arr[i]] + " thousand ";
                i--;
            }
        }
        cout<<str<<endl;
    }
    return 0;
}

/*
#include<iostream>
#include <string.h>
using namespace std;
void duChar(char a)
{
    if(a=='1')
        cout<<"one";
    else if(a=='2')
        cout<<"two";
    else if(a=='3')
        cout<<"three";
    else if(a=='4')
        cout<<"four";
    else if(a=='5')
        cout<<"five";
    else if(a=='6')
        cout<<"six";
    else if(a=='7')
        cout<<"seven";
    else if(a=='8')
        cout<<"eight";
    else if(a=='9')
        cout<<"nine";
}
void myfun(char a,char b,char c)
{
    if(!(a>='0'&&a<='9'&&b>='0'&&b<='9'&&c>='0'&&c<='9'))
    {
        if(a!='@'&&b!='@'&&c!='@')
        {
            cout<<"error";
            return;
        }
    }
    if(a>='1'&&a<='9')
    {
        duChar(a);
        cout<<" hundred and ";
    }
    if(b=='1'&&c=='0')
        cout<<"ten";
    else if(b=='1'&&c=='1')
        cout<<"eleven";
    else if(b=='1'&&c=='2')
        cout<<"twelve";
    else if(b=='1'&&c=='3')
        cout<<"thirteen";
    else if(b=='1'&&c=='4')
        cout<<"fourteen";
    else if(b=='1'&&c=='5')
        cout<<"fifteen";
    else if(b=='1'&&c=='6')
        cout<<"sixteen";
    else if(b=='1'&&c=='7')
        cout<<"seventeen";
    else if(b=='1'&&c=='8')
        cout<<"eighteen";
    else if(b=='1'&&c=='9')
        cout<<"nineteen";
    else if(b=='2')
        cout<<"twenty";
    else if(b=='3')
        cout<<"thirty";
    else if(b=='4')
        cout<<"forty";
    else if(b=='5')
        cout<<"fifty";
    else if(b=='6')
        cout<<"sixty";
    else if(b=='7')
        cout<<"seventy";
    else if(b=='8')
        cout<<"eighty";
    else if(b=='9')
        cout<<"ninety";
    if((b>'1'&&b<='9'||b=='@'||b=='0')&&c>='1'&&c<='9')
    {
        if(!(b=='@'||b=='0'))
            cout<<' ';
        duChar(c);
    }
}
int main() {
    char str[500];
    while(cin>>str)
    {
        int len=strlen(str);
        if(len>10)
        {
            cout<<"error"<<endl;
            return -1;
        }
        char sc[10];
        for(int i=0;i<10;i++)
            sc[i]='@';
        for(int i=0;i<len;i++)
            sc[9-i]=str[len-1-i];
        if(sc[0]!='@')
        {
            duChar(sc[0]);
            cout<<" billion ";
        }
        for(int i=0;i<3;i++)
        {
            if(sc[3*i+3]!='@')
            {
                //      if(i==2&&sc[7]=='0')
                //          cout<<"and ";
                myfun(sc[3*i+1],sc[3*i+2],sc[3*i+3]);
                if(i==0)
                {
                    if(!(sc[1]=='0'&&sc[2]=='0'&&sc[3]=='0'))
                        cout<<" million ";
                }
                else if(i==1){
                    if(!(sc[4]=='0'&&sc[5]=='0'&&sc[6]=='0'))
                        cout<<" thousand ";
                }
                
            }
        }
        cout<<endl;
    }
    return 0;
}
*/

