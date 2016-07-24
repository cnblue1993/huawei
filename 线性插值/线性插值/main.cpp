//
//  main.cpp
//  线性插值
//
//  Created by anne on 16/7/10.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int m,n,x,y;
    int max = 0, min = INT16_MAX;
    int maxValue = 0, minValue = 0;
    while (cin>>m>>n) {
        while(m--){
            cin>>x>>y;
            if(x>max){
                max = x;
                maxValue = y;
            }
            if(x<min){
                min = x;
                minValue = y;
            }
        }
        int temp = (maxValue - minValue) / (max - min);
        for(int i = 0; i < max-min+1; i++){
            cout<<min+i<<" "<<(minValue + temp*i)<<endl;
        }
        
        
    }
    return 0;
}
