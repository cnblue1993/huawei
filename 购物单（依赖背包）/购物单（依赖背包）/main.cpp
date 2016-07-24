//
//  main.cpp
//  购物单（依赖背包）
//
//  Created by anne on 16/5/6.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(int argc, const char * argv[]) {
    int N,m;
    while(cin>>N>>m){
        vector<int> v(61,0);
        vector<int> p(61,0);
        vector<int> q(61,0);
        
        vector<int> fv(61,0);
        vector<int> fp(61,0);
        vector<vector<int>> fq(61,vector<int> (0));
        vector<int> dp(200000,0);
        vector<int> rem(61,0);
        int t = 1;
        for(int i = 1; i <= m; i++){
            cin>>v[i]>>p[i]>>q[i];
            if(q[i] == 0){
                fv[t] = v[i];
                fp[t] = p[i];
                rem[t] = i;
                t++;
            }
            if(q[i]!= 0)
                fq[q[i]].push_back(i);
            
        }
        
        int money = 0;
        for(int j = 1; j < t; j++){
            int num = rem[j];
            for(int i = N; i >= fv[j]; i--){
                int maxnum = dp[i];
                maxnum = max(maxnum, dp[i - fv[j]] + fv[j] * fp[j]);    //主件
                if(fq[num].size() == 1 && i - fv[j] - v[fq[num][0]] >= 0){  //附件
                    maxnum = max(maxnum, dp[i - fv[j] - v[fq[num][0]]] + fv[j] * fp[j] + v[fq[num][0]] * q[fq[num][0]]);
                }
                if(fq[num].size() == 2){
                    if(i - fv[j] - v[fq[num][0]] >= 0)
                        maxnum = max(maxnum, dp[i - fv[j] - v[fq[num][0]]] + fv[j] * fp[j] + v[fq[num][0]] * q[fq[num][0]]);
                    if(i - fv[j] - v[fq[num][1]] >= 0)
                        maxnum = max(maxnum, dp[i - fv[j] - v[fq[num][1]]] + fv[j] * fp[j] + v[fq[num][1]] * q[fq[num][1]]);
                    if(i - fv[j] - v[fq[num][0]] - v[fq[num][1]] >= 0)
                        maxnum = max(maxnum, dp[i - fv[j] - v[fq[num][0]]] + fv[j] * fp[j] + v[fq[num][0]] * q[fq[num][0]] + v[fq[num][1]] * q[fq[num][1]]);
                }
                dp[i] = maxnum;
                money = max(dp[i],money);
            }
        }
        cout<<money<<endl;
    }
    return 0;
}

//注意区别从前计算到从后计算dp 的区别


//#include<stdio.h>
//int main()
//{
//    int N,m,i,j,k=0;
//    int v[61];
//    int p[61];
//    int q[61];
//    int path[61][20000];
//    int tv[61];                                 //物品总价值:tv[i]=v[i]*p[i]
//    while(scanf("%d" "%d",&N,&m)!=EOF)
//    {
//        for(i=1;i<=m;i++)
//        {
//            scanf("%d" "%d" "%d",&v[i],&p[i],&q[i]);
//            tv[i]=v[i]*p[i];
//        }
//        for(i=1;i<=m;i++)
//        {
//            for(j=1;j<=N;j++)
//            {
//                if(q[i]==0)           //没有附属品
//                {
//                    if(v[i]>j)            //放不下第i个物品
//                    {
//                        path[i][j]=0;
//                    }
//                    else
//                    {
//                        if(path[i-1][j-v[i]]+tv[i]>path[i-1][j])  //放入物品i比不放，总价值大
//                        {
//                            path[i][j]=path[i-1][j-v[i]]+tv[i];
//                        }
//                        else                                   //不放入价值更大
//                        {
//                            path[i][j]=path[i-1][j];
//                        }
//                    }
//                    
//                }
//                else                                     //含有主件
//                {
//                    if(v[i]+v[q[i]]>j)                //放不下i及其主件
//                    {
//                        path[i][j]=0;
//                    }
//                    else                             //与上面一样处理
//                    {
//                        if(path[i-1][j-v[i]]+tv[i]>path[i-1][j])
//                        {
//                            path[i][j]=path[i-1][j-v[i]]+tv[i];
//                        }
//                        else
//                        {
//                            path[i][j]=path[i-1][j];
//                        }
//                        
//                    }
//                }
//                
//            }
//        }
//        printf("%d\n",path[m][N]);
//    }
//}