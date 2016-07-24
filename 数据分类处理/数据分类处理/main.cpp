//
//  main.cpp
//  数据分类处理
//
//  Created by anne on 16/5/7.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

int main(){
    
    int n,m,i,j,k;
    while(cin>>n){
        int con=0,result[100]={0},count[100]={0},tem=0,len=0,len1=0;
        char a[100][100]={0},b[100][100]={0},temp[100]={0},res[100][100]={0};
        string s1,s2;
        for(i=0;i<n;i++) cin>>a[i];
        cin>>m;
        for(i=0;i<m;i++) cin>>b[i];
        len=m;
        for(i=0;i<len;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(j>m-1)break;
                if(atoi(b[i])>atoi(b[j]))
                {
                    strncpy(temp,b[i],100);
                    strncpy(b[i],b[j],100);
                    strncpy(b[j],temp,100);
                }
                else if(atoi(b[i])==atoi(b[j]))
                {
                    for(k=j;k<=len;k++) strncpy(b[k],b[k+1],100);
                    j--;
                    m--;
                }
            }
        }
        for(i=0;i<m;i++)
        {
            s1=b[i];
            len1=(int)s1.size();
            tem=con;
            for(j=0;j<n;j++)
            {
                s2=a[j];
                len=(int)s2.size();
                for(k=0;k<=len-len1;k++)
                {
                    if(s2.substr(k,len1)==s1)
                    {
                        strncpy(res[con],a[j],100);
                        result[con++]=j;
                        break;
                    }
                }
            }
            count[i]=con-tem;
        }
        len=m;
        for(i=0;i<m;i++) if(count[i]==0)len--;
        tem=con*2+len*2;
        cout<<tem<<' ';
        tem=0;
        for(i=0;i<m;i++)
        {
            if(count[i]>0)
            {
                cout<<b[i]<<' '<<count[i]<<' ';
                for(j=0;j<count[i];j++)
                {
                    if((j+tem)!=(con-1))
                        cout<<result[j+tem]<<' '<<res[j+tem]<<' ';
                    else 
                        cout<<result[j+tem]<<' '<<res[j+tem]<<endl;
                }
                tem+=count[i];
            }
        }
    }
    return 0;
}
