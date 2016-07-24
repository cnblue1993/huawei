//
//  main.cpp
//  24点游戏算法
//
//  Created by anne on 16/7/17.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

//int isSolve = 0;

void find24(int index, int sum, int num[], bool &isSolve){
    
    if(sum == 24){
        isSolve = true;
        
    }
    if(isSolve || sum > 24 || index >= 4)
        return;
    
    for(int i = 0; i < 4; i++){
        switch (i) {
            case 0:
                find24(index + 1, sum + num[index], num, isSolve);
                break;
            case 1:
                find24(index + 1, sum - num[index], num, isSolve);
                break;
            case 2:
                find24(index + 1, sum * num[index], num, isSolve);
                break;
            case 3:
                find24(index + 1, sum / num[index], num, isSolve);
                break;
        }
        if(isSolve)
            return;
    }
}

int main(int argc, const char * argv[]) {
    int num[4];
    while(cin>>num[0]>>num[1]>>num[2]>>num[3]){
        sort(num,num+4);
        bool isSolve = false;
        do
        {
            find24(1, num[0], num, isSolve);
            if(isSolve)
                break;
        } while (next_permutation(num,num+4));//全排列
    
        if(isSolve)
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }
    return 0;
}



//int Calculate ( int x, int y, int z, int w); //运算表达式的所有情况
//int main()
//{
//    int i,k,j;
//    int nnum[4];
//    while(cin>>nnum[0])
//    {
//        int flag=0,sum=0;
//        for(i=1;i<4;i++)
//            cin>>nnum[i];
//        for(i=0;i<4;i++)
//        {
//            for(j=0;j<4;j++)
//            {
//                for(k=0;k<4;k++)
//                {
//                    if(i!=j&&i!=k&&j!=k&&Calculate(nnum[i],nnum[j],nnum[k],nnum[6-i-j-k]))
//                        flag=1;
//                    if(flag)break;
//                }
//                if(flag)break;
//            }
//            if(flag)break;
//        }
//        if(flag)cout<<"true"<<endl;
//        else cout<<"false"<<endl;
//    }
//    //return 0;
//}
//int Calculate ( int x, int y, int z, int w) //运算表达式的所有情况
//{
//    int flag=0;
//    if (x+y+z+w==24)flag=1;
//    else if (x+y+z-w==24) flag=1;
//    else if ((x+y)*(z+w)==24) flag=1;
//    else if ((x-y)*(z+w)==24) flag=1;
//    else if ((x-y)*(z-w)==24) flag=1;
//    else if ((x+y+z)*w==24) flag=1;
//    else if ((x-y-z)*w==24) flag=1;
//    else if ((x+y-z)*w==24) flag=1;
//    else if ((x*y*z)/w==24) flag=1;
//    else if ((x*y)*(z+w)==24) flag=1;
//    else if ((x*y)*(z-w)==24)flag=1;
//    else if ((x*y)*z-w==24)flag=1;
//    else if ((x*y)*z+w==24) flag=1;
//    else if (x*y*z*w==24) flag=1;
//    else if ((x+y)+(z/w)==24) flag=1;
//    else if ((x+y)*(z/w)==24) flag=1;
//    else if ((x*y)+z+w==24) flag=1;
//    else if ((x*y)+z-w==24) flag=1;
//    else if ((x*y)-(z/w)==24) flag=1;
//    else if ((x*y)+(z/w)==24) flag=1;
//    else if ((x*y)-z-w==24) flag=1;
//    else if ((x*y)+(z*w)==24) flag=1;
//    else if ((x*y)-(z*w)==24) flag=1;
//    else if ((x*y)/(z*w)==24) flag=1;
//    else if ((z-w)!=0&&(x*y)/(z-w)==24) flag=1;
//    else if ((x*y)/(z+w)==24) flag=1;
//    //  else flag=0;
//    
//    return flag;
//}
