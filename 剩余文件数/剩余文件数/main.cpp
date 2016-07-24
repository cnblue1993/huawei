//
//  main.cpp
//  剩余文件数
//
//  Created by anne on 16/5/9.
//  Copyright © 2016年 anne. All rights reserved.
//
/*
 剩余的文件数
 描述:
 在一个空的文件夹中，即可以装订增加文件数，也可以摘除减少文件数，在多次装订、摘除后，请输出最后剩余的文件数
 注：如果摘除的文件数大于当前的文件数，则将当前的文件全部摘除
 运行时间限制:	无限制
 内存限制:	无限制
 输入:
 装订文件数：
 binding 20
 表明装订20个文件
 
 摘除文件数:
 remove 20
 表明摘除20个文件
 
 结束装订摘除:
 end
 输出:
 当前文件夹的文件数
 current 20
 表明当前还有20个文件在文件夹中
 样例输入:
 binding 30
 remove 20
 binding 10
 remove 10
 end
 样例输出:
 current 10
 */

#include <iostream>
#include <string>

using namespace std;
int main(int argc, const char * argv[]) {
    string cmd;
    int num;
    int current = 0;
    while(cin>>cmd){
        if(cmd == "end")
            break;
        cin >> num;
        if(cmd == "binding"){
            current += num;
        }else if(cmd == "remove"){
            if(num >= current)
                current=0;
            else
                current -= num;
        }
    }
    cout<<"current "<<current<<endl;
    return 0;
}
