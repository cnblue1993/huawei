//
//  main.cpp
//  合唱团
//
//  Created by anne on 16/5/7.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
using namespace std;

const int maxn = 1000 + 1;

int main()
{
    int n;
    int a[maxn];
    int f1[maxn];
    int f2[maxn];
    
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    for(int i=0;i<n;i++)
    {
        f1[i] = 1;
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j]&&f1[i]<f1[j]+1)
                f1[i]= f1[j]+1;
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        f2[i] = 1;
        for (int j=i+1;j<n;j++)
        {
            if(a[i]>a[j]&&f2[i]<f2[j]+1)
                f2[i]=f2[j]+1;
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++)
        if(ans<f1[i]+f2[i]-1) 
            ans=f1[i]+f2[i]-1;
    
    cout<<n-ans<<endl;
    return 0;
}
