//
//  main.cpp
//  完全数计算
//
//  Created by anne on 16/7/10.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>

using namespace std;

int fac(int n){
    int sum = 0;
    for(int i = 1; i <= n/2; i++){
        if(n % i == 0)
            sum += i;
    }
    return sum;
}
int completeNum(int n){
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(i == fac(i))
            count++;
    }
    return count;
}
int main(int argc, const char * argv[]) {
    int n;
    while (cin>>n) {
        cout<<completeNum(n)<<endl;
    }
    return 0;
}
