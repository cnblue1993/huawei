//
//  main.cpp
//  明明的随机数
//
//  Created by anne on 16/5/4.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void random(vector<int> num){
    int n = (int)num.size();
    vector<bool> temp(1001,false);
    int max = 0;
    for(int i = 1; i < n; i++){
        temp[num[i]] = true;
        if(num[i] > max)
            max = num[i];
    }
    for(int i = 1; i <= max; i++){
        if(temp[i]){
            cout<<i<<endl;
        }
    }
}

int main(int argc, const char * argv[]) {
    int n,x;
    while(cin>>n){
        vector<int> num(n,0);
        while (n--) {
            cin>>x;
            num.push_back(x);
        }
        random(num);
    }
    
    return 0;
}
