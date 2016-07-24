//
//  main.cpp
//  放苹果
//
//  Created by anne on 16/7/17.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>

using namespace std;

//m-apple n-plate
//(m，n)=(m,n-1)+(m-n,n);

int count(int m, int n){
    if(m < 0)
        return 0;
    if(m == 1 || n == 1)
        return 1;
    return count(m,n-1) + count(m-n,n);
}

int main(int argc, const char * argv[]) {
    int m,n;
    while(cin>>m>>n){
        cout<<count(m,n)<<endl;
    }
    return 0;
}
