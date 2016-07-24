//
//  main.cpp
//  计算日期到天数转换
//
//  Created by anne on 16/7/18.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>

using namespace std;

int is_leapYear(int y){
    if(y % 4 == 0 && y % 100 != 0)
        return 1;
    else if (y % 400 == 0)
        return 1;
    else
        return 0;
}

int count(int y, int m, int d, int mouth[]){
    if(y < 0 || m <= 0 || m >12 || d <=0 || d > mouth[m])
        return -1;
    int days = 0;
    for(int i = 1; i < m; i++){
        if(i == 2 && is_leapYear(y))
            days++;
        days += mouth[i];
    }
    days += d;
    return days;
}

int main(int argc, const char * argv[]) {
    int mounth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int y, m, d;
    while(cin>>y>>m>>d){
        cout<<count(y, m, d, mounth)<<endl;
    }
    return 0;
}
