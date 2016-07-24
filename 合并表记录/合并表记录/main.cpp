//
//  main.cpp
//  合并表记录
//
//  Created by anne on 16/5/5.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
int n;
    int key;
    int value;
    map<int,int> m;
    while (cin>>n) {
        map<int,int> m;
        while(n--){
            cin>>key>>value;
            if(m.find(key)==m.end())
                m.emplace(key,value);
            else
                m[key] += value;
        }
        for(auto x:m){
            cout<<x.first<<" "<<x.second<<endl;
        }
    }
    return 0;
}
