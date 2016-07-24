//
//  main.cpp
//  统计每个月兔子的总数
//
//  Created by anne on 16/5/26.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void countRabbit(int month){
    vector<int> focci(month,0);
    focci[0] = focci[1] = 1;
    for(int i = 2; i < month; i++){
        focci[i] = focci[i - 1] + focci[i - 2];
    }
    cout<<focci[month - 1]<<endl;
}

int main(int argc, const char * argv[]) {
    int month;
    while(cin>>month){
        countRabbit(month);
    }
    return 0;
}
