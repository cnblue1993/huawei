//
//  main.cpp
//  识别有效的IP地址和掩码并进行分类统计
//
//  Created by anne on 16/5/6.
//  Copyright © 2016年 anne. All rights reserved.
//

//input:
//IP~MASK

//output:
//count: A B C D E error private

//A类地址1.0.0.0~126.255.255.255;
//B类地址128.0.0.0~191.255.255.255;
//C类地址192.0.0.0~223.255.255.255;
//D类地址224.0.0.0~239.255.255.255；
//E类地址240.0.0.0~255.255.255.255

//私网IP范围是：
//10.0.0.0～10.255.255.255
//172.16.0.0～172.31.255.255
//192.168.0.0～192.168.255.255

//对掩码还需要判断是否前面都是连续的1，判断方法是：将掩码转化成32无符号整型，取反为000……00111……1，然后再加1为00……01000……0，此时为2^n，如果满足就为合法掩码。

#include <iostream>
#include <string.h>
using namespace std;
int isLowFullOne(int n){
    if(n == 0)
        return 0;
    if((n & (n+1)) == 0)
        return 1;
    else
        return 0;
}
int isContinuousOne(int n){ //是否为连续的1

    while(n){   //去掉末尾连续的0
        if((n&1)==0)
            n = n>>1;
        else
            break;
    }
    return (n&(n+1))==0?1:0;
}

int isPrivateNet(int ip[])
{
    switch(ip[0]){
        case 10:
            if(ip[1] >= 0&&ip[1] <= 255){
                return 1;
            }
        case 172:
            if(ip[1] >= 16&&ip[1] <= 31){
                return 1;
            }
        case 192:
            if(ip[1] == 168){
                return 1;
            }
        default:
            return 0;
    }
}

int isWhichAddr(int ip[])
{
    if(ip[0] >= 1&&ip[0] <= 126){
        return 0;
    }else if(ip[0] >= 128&&ip[0] <= 191){
        return 1;
    }else if(ip[0] >= 192&&ip[0] <= 223){
        return 2;
    }else if(ip[0] >= 224&&ip[0] <= 239){
        return 3;
    }else if(ip[0] >= 240&&ip[0] <= 255){
        return 4;
    }
    return -1;
}

int isRightMask(int ip[])
{
    int i;
    int flag = 0;
    for(i = 7;i >= 4;i--){
        if(flag == 1){
            if(!isLowFullOne(ip[i]) && ip[i] != 255)
                return 0;
        }
        if(ip[i] != 0){
            flag = 1;
            if(i != 7){
                if(!isContinuousOne(ip[i]))
                    return 0;
            }
            else{
                //低位不能全为1的连续的1的数
                if(!isContinuousOne(ip[i]))
                    return 0;
                if(isLowFullOne(ip[i]))
                    return 0;
            }
        }
    }
    if(ip[7] == 255&&ip[6] == 255&&ip[5] == 255&&ip[4] == 255)
        return 0;
    else
        return 1;
}

int isAddr(int ip[])
{
    for(int i = 0;i < 8;i++){
        if(ip[i] > 255 || ip[i] < 0)
            return 0;
    }
    return 1;
}

void init(int ipmask[],int n){
    int i;
    for(i = 0;i < n;i++)
        ipmask[i] = 0;
}

int main()
{
    int flag;
    int i,k;
    char str[100];
    int ipmask[8] = {0};
    int state[7] = {0};
    
    while(gets(str)){
        flag = 0;
        i = 0;
        k = 0;
        init(ipmask,8);
        while(str[i] != '\0'){
            if(str[i] >= '0' && str[i] <= '9') //如果是数字
                ipmask[k] = ipmask[k]*10 + str[i] - '0';
            else if(str[i] == '.' || str[i] == '~'){ //如果是.或者~表示一个数字结束
                k++;
                if((k > 7) || (str[i+1] != '\0' && (str[i+1]== '.' || str[i+1] == '~'))){//当数字个数大于8个时，或者连继的点和~
                    flag = 1;
                    break;
                }
            }
            else{  //如果有其他的字符
                flag = 1;
                break;
            }
            i++;
        }
        if(flag == 1 || !isAddr(ipmask) || !isRightMask(ipmask))
            state[5] += 1;
        else{
            state[isWhichAddr(ipmask)] += 1;
            if(isPrivateNet(ipmask))
                state[6] += 1;
        }
    }
    for(i = 0;i < 7;i++){
        if(i != 6)
            cout << state[i] << " ";
        else
            cout << state[i] << endl;
    }
    return 0;
}

//#include <iostream>
//#include <string>
//#include <vector>
//#include <math.h>
//
//using namespace std;
//
//int check(vector<int> &a, vector<int> &b){//0-error 1-A 2-B 3-C 4-D 5-E 6，7，8-PRIVATE
//    unsigned int mask_int=0;
//    for(int i = 0; i < 4; i++){
//        if(i == 0){
//            if(!(a[i]>=1 && a[i]<= 255))
//                return 0;
//        }else{
//            if(!(a[i]>=0 && a[i]<= 255))
//                return 0;
//        }
//        mask_int=mask_int*256+b[i];
//    }
//
//    mask_int=~mask_int+1;
//    unsigned int test=0x01;
//    int flag=0;
//    for(int i=0;i<32;i++){
//        if(mask_int==test<<i){
//            flag=1;
//            break;
//        }
//    }
//    if(flag==0){
//        return 0;
//    }
//    for(int i = 0; i < 4; i++){
//        a[i] = a[i] & b[i];
//    }
//
//    if((a[0] >= 1 && a[0] <= 126)&& a[1] == 0 && a[2] == 0 && a[3] == 0){
//        if(a[0] == 10)
//            return 6;
//        else
//            return 1;
//    }else if((a[0] >= 128 && a[0] <= 191)&& (a[1] >= 0 && a[1] <= 255) && a[2] == 0 && a[3] == 0){
//        if(a[0] == 172 && (a[1] >= 16 && a[1] <= 31))
//            return 7;
//        else
//            return 2;
//    }else if((a[0] >= 192 && a[0] <= 223)&& (a[1] >= 0 && a[1] <= 255) && (a[2] >= 0 && a[2] <= 255) && a[3] == 0){
//        if(a[0] == 192 && a[1] == 168)
//            return 8;
//        else
//            return 3;
//    }else if((a[0] >= 224 && a[0] <= 239)&& (a[1] >= 0 && a[1] <= 255) && (a[2] >= 0 && a[2] <= 255) && a[3] == 0){
//            return 4;
//    }else{
//        return 5;
//    }
//    
//}
//int ipAndMask(string s){
//    vector<int> ip(4,0);
//    vector<int> a(4,0);
//    vector<int> b(4,0);
//    int len = (int)s.length();
//    string temp;
//    bool mask= false;
//    int t = 0;
//    for(int i = 0; i < len; i++){
//        if(s[i] == '.' || s[i] == '~'){
//            int n = (int)temp.length();
//            int num = 0;
//            for(int j = 0; j < n; j++){
//                num += (temp[j] - '0') * pow(10,n-1-j);
//            }
//            if(n == 0)
//                num = -1;
//            if(mask)
//                b[t] = num;
//            else
//                a[t] = num;
//            temp = "";
//            t++;
//            if(s[i] == '~'){
//                t = 0;
//                mask = true;
//            }
//        }else{
//            temp += s[i];
//        }
//    }
//    int n = (int)temp.length();
//    int num = 0;
//    for(int j = 0; j < n; j++){
//        num += (temp[j] - '0') * pow(10,n-1-j);
//    }
//    if(n == 0)
//        num = -1;
//    b[3] = num;
//    return check(a,b);
//}
//
//int main(int argc, const char * argv[]) {
//    string s;
//    int error=0,a=0,b=0,c=0,d=0,e=0,p=0;
//    while(cin>>s){
//        switch (ipAndMask(s)) {
//            case 0:
//                error++;
//                break;
//            case 1:
//                a++;
//                break;
//            case 2:
//                b++;
//                break;
//            case 3:
//                c++;
//                break;
//            case 4:
//                d++;
//                break;
//            case 5:
//                e++;
//                break;
//            case 6:
//                a++;
//                p++;
//                break;
//            case 7:
//                b++;
//                p++;
//                break;
//            case 8:
//                c++;
//                p++;
//                break;
//            default:
//                break;
//        }
//    }
//    cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<error<<" "<<p<<endl;
//    return 0;
//}

