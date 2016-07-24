//
//  main.cpp
//  挑7
//
//  Created by anne on 16/7/10.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>

using namespace std;

int main(){
    int n;
    while (cin>>n) {
        int count = 0;
        for(int i = 7; i <= n; i++){
            if(i % 7 == 0)
                count++;
            else{
                int temp = i;
                while(temp >=7){
                    if(temp % 10 == 7){
                        count++;
                        break;
                    }
                    temp /=10;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
