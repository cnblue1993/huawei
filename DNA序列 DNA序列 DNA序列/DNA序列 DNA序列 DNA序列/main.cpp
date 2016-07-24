//
//  main.cpp
//  DNA序列 DNA序列 DNA序列
//
//  Created by anne on 16/7/17.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int isCorG(char a){
    if(a == 'C' || a == 'G')
        return 1;
    else
        return 0;
}
void GC_Ratio(string dna,int k){
    int len = (int) dna.length();
    if(k >= len){
        cout<<dna<<endl;
        return;
    }
    vector<vector<int>> dp(k+1,vector<int>(len,0));
    int max = 0;
    int index = 0;
    for(int j = 0; j < len; j++)
        dp[1][j] = isCorG(dna[j]);
    
    for(int i = 2; i < k+1; i++){
        for(int j = 0; j < len; j++){
            if(j < (i-1))
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = isCorG(dna[j-i+1]) + dp[i-1][j];

            if(dp[i][j] > max && i == k && (j + 1) > (k-1)){
                max = dp[i][j];
                
                index = j;
            }
           // cout<<dp[i][j] <<" ";
        }
       // cout<<endl;
    }
    cout<<dna.substr(index-k+1, k)<<endl;
}


int main(int argc, const char * argv[]) {
    string dna;
    int k;
    while(cin>>dna>>k){
        GC_Ratio(dna, k);
    }
    return 0;
}
