//
//  main.cpp
//  四则运算
//
//  Created by anne on 16/7/10.
//  Copyright © 2016年 anne. All rights reserved.
//

//编译原理实现
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <cctype>
using namespace std;

char strExp[102]; // 表达式
int i = 0;      // 表达式指针
int T();
int E1(int);
int T2();
int E2(int);
int T3();

int E()
{
    int anst = T(); //表达式T的结果
    return E1(anst);
} // 对表达式的描述

int T()
{
    int preresult = T2();
    return E2(preresult);
}

int E1(int preresult)
{
    // 传递一个属性
    int ans = preresult;
    if(i < strlen(strExp))
    {
        if(strExp[i] == '+'){
            i++;
            int nextResult = T();
            preresult = preresult + nextResult;
            ans = E1(preresult);
        }
        else if(strExp[i] == '-'){
            i++;
            int nextResult = T();
            preresult = preresult - nextResult;
            ans = E1(preresult);
        }
        else
        {
            //非法状态或某种其它状态
        }
        
    }
    return ans;
}

int E2(int preresult)
{
    int ans = preresult;
    if(i < strlen(strExp))
    {
        if(strExp[i] == '*'){
            i++;
            int nextResult = T2();
            preresult = preresult*nextResult;
            ans = E2(preresult);
        }else if(strExp[i] == '/'){
            i++;
            int nextResult = T2();
            preresult = preresult/nextResult;
            ans = E2(preresult);
        }
        else
        {
            //非法状态
        }
        
    }
    return ans;
}

int T2()
{
    int ans = 0;
    int sign = 1;
    if(i < strlen(strExp))
    {
        
        if(strExp[i] == '-'){
            sign = -1;
            i++;
        }
        if(isalnum(strExp[i]))
        {
            while(i < strlen(strExp) && isalnum(strExp[i]))
            {
                ans = ans * 10 + (strExp[i] - '0');
                i++;
            }
            ans = ans * sign;
        }
        else if(strExp[i] == '(' || strExp[i] == '[' || strExp[i] == '{')
        {
            char bracket = strExp[i];
            i++;
            ans = E();
            if(i < strExp[i])
            {
                if((bracket == '(' && strExp[i] == ')') ||
                   (bracket == '[' && strExp[i] == ']')||
                   (bracket == '{' && strExp[i] == '}'))
                    i++;
                // 解析完毕，取下一个表达式值
            }
            else
            {
                //printf("error on %d th char",i);
                //产生错误，括号不配对错误。
            }
        }
        else
        {
            // 非法状态
        }
        
    }
    return ans;
}

int T3()
{
    int ans = 0;
    if(strExp[i] == '(')
    {
        i++;
        ans = E();
        if(strExp[i] == ')')
        {
            i++;
        }
        else
        {
            // grammer error
        }
    }
    else
    {
        ans = E();
    }// 内部不是(，则跟一个表达式
    return ans;
}

int main()
{
    
    i = 0;
    scanf("%s",strExp);
    int ans = E();
    printf("%d\n",ans);
    return 0;
}

//#include <iostream>
//#include <string.h>
//#include <stack>
//#include <vector>
//using namespace std;
//
//bool isHigh(char top_op,char InfixExp_op)
////判断操作符的优先级;
////top_op为栈顶操作符
////InfixExp_op为当前读入操作符
////如果栈顶操作符优先级高，则弹出栈顶操作符;
////如果栈顶操作符优先级低，则压入当前读入操作符;
//{
//    if ((top_op== '+')&&(InfixExp_op== '+')) return true;
//    if ((top_op== '+')&&(InfixExp_op== '-')) return true;
//    if ((top_op== '-')&&(InfixExp_op== '+')) return true;
//    if ((top_op== '-')&&(InfixExp_op== '-')) return true;
//    if ((top_op== '*')&&(InfixExp_op== '+')) return true;
//    if ((top_op== '*')&&(InfixExp_op== '-')) return true;
//    if ((top_op== '*')&&(InfixExp_op== '*')) return true;
//    if ((top_op== '*')&&(InfixExp_op== '/')) return true;
//    if ((top_op== '/')&&(InfixExp_op== '+')) return true;
//    if ((top_op== '/')&&(InfixExp_op== '-')) return true;
//    if ((top_op== '/')&&(InfixExp_op== '*')) return true;
//    if ((top_op== '/')&&(InfixExp_op== '/')) return true;
//    if (InfixExp_op== ')') return true;
//    return false;
//}
//
//int main()
//{
//    char str[5000];
//    while(cin>>str)
//    {
//        int len=strlen(str);
//        stack<char> sta;
//        vector<int> vec;
//        vector<bool> vec_b;
//        int sum=0;
//        int flag=1;
//        int flb=0;//两个相邻的数之间运算符的个数，挑负数;
//        for(int i=0;i<len;++i)
//        {
//            if(i==0&&str[i]=='-')//把负号挑出来;
//            {
//                flag=-1;
//                continue;
//            }
//            if(i>0&&str[i]=='-'&&flb==1)//把负号挑出来;
//            {
//                flag=-1;
//                continue;
//            }
//            if(str[i]>='0'&&str[i]<='9')
//            {
//                sum=sum*10+(str[i]-'0');
//                if(!(str[i+1]>='0'&&str[i+1]<='9'))
//                {
//                    sum*=flag;
//                    vec.push_back(sum);
//                    vec_b.push_back(true);//真为数，假为运算符的;
//                    sum=0;
//                    flag=1;
//                    flb=0;
//                }
//            }
//            else
//            {
//                if(str[i]=='['||str[i]=='{')
//                    str[i]='(';
//                if(str[i]==']'||str[i]=='}')
//                    str[i]=')';
//                if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
//                    ++flb;
//                if (sta.empty())
//                    //栈为空，压入操作符;
//                    sta.push(str[i]);
//                else if(isHigh(sta.top(),str[i]))
//                    //栈顶操作符优先,比如栈顶为*,当前操作符为+，则弹出*
//                {
//                    if (str[i]!= ')')
//                        //非闭括号;
//                        //弹出栈中操作符直到栈顶操作数优先级低于当前读入操作数;
//                        //压入当前读入操作符;
//                    {
//                        do
//                        {
//                            if(sta.top()!='('||sta.top()!=')')
//                            {
//                                vec.push_back(sta.top());
//                                vec_b.push_back(false);
//                            }
//                            sta.pop();
//                        }while((!sta.empty())&&(isHigh(sta.top(),str[i])));
//                        sta.push(str[i]);
//                    }
//                    else
//                        //闭括号;
//                    {
//                        while((!sta.empty())&&(sta.top()!= '('))
//                            //弹出直到开括号;
//                        {
//                            if(sta.top()!='('||sta.top()!=')')
//                            {
//                                vec.push_back(sta.top());
//                                vec_b.push_back(false);
//                            }
//                            sta.pop();
//                        }
//                        if ((!sta.empty())&&(sta.top()== '('))
//                            sta.pop();
//                        //弹出开括号;
//                    }
//                }
//                else if(!isHigh(sta.top(),str[i]))
//                    //中缀表达式中操作符优先;
//                    //比如栈顶为+,而当前读入*;
//                {
//                    sta.push(str[i]);
//                    //压入当前读入操作符;
//                }
//            }
//        }
//        while(!sta.empty())
//            //把栈中剩余的操作符依次弹出;
//        {
//            if(sta.top()!='('||sta.top()!=')')
//            {
//                vec.push_back(sta.top());
//                vec_b.push_back(false);
//            }
//            sta.pop();
//        }
//        while(!sta.empty())
//            sta.pop();
//        stack<int> sta_i;
//        int mm=vec.size();
//        int res=0;
//
//        for (int i=0;i<mm;++i)
//        {
//            if(vec_b[i])
//            {
//                sta_i.push(vec[i]);
//            }
//            else
//            {
//                int t1=0;
//                int t2=0;
//                int t3=0;
//                if(!sta_i.empty())
//                {
//                    t1=sta_i.top();
//                    sta_i.pop();
//                }
//                if (!sta_i.empty())
//                {
//                    t2=sta_i.top();
//                    sta_i.pop();
//                }
//                if(vec[i]==43)
//                    t3=t1+t2;
//                else if(vec[i]==45)
//                    t3=t2-t1;
//                else if(vec[i]==42)
//                    t3=t2*t1;
//                else if(vec[i]==47)
//                    t3=t2/t1;
//                sta_i.push(t3);
//            }
//        }
//        if (!sta_i.empty())
//            res=sta_i.top();
//        cout<<res<<endl;
//        while(!sta_i.empty())
//            sta_i.pop();
//        vec.clear();
//    }
//    return 0;
//}
