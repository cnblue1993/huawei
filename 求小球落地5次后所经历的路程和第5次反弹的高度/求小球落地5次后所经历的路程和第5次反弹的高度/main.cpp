//
//  main.cpp
//  求小球落地5次后所经历的路程和第5次反弹的高度
//
//  Created by anne on 16/5/26.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void calHigh(float h){
    float sum = h;
    for(int i = 0; i < 4; i++){
        sum += (h/2) * 2;
        h /= 2;
    }
    cout<<sum<<endl;
    cout<<h/2<<endl;
}

int main(int argc, const char * argv[]) {
    float h;
    while(cin>>h){
        calHigh(h);
    }
    return 0;
}
