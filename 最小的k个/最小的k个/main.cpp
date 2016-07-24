//
//  main.cpp
//  最小的k个
//
//  Created by anne on 16/7/10.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int n,k;
    while (cin>>n>>k) {
        vector<int> mink(k);
        int x;
        for(int i = 0; i < n; i++){
            cin>>x;
            if(i < k-1){
                mink[i] = x;
            }else if(i == k-1){
                mink[i] = x;
                sort(mink.begin(), mink.end());
            }else{
                if(x < mink[k-1]){
                    mink[k-1] = x;
                    sort(mink.begin(), mink.end());
                }
            }
        }
        for(int i = 0; i < k-1; i++)
            cout<<mink[i]<<" ";
        cout<<mink[k - 1]<<endl;
    }
    return 0;
}

