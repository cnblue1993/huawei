//
//  main.cpp
//  火车进站
//
//  Created by anne on 16/7/18.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void helper(string &in, vector<string> &out, int index){
    if(index == in.size()){
        return;
    }
    if(index == 0){
        string outNum = "";
        outNum += in[index];
        out.push_back(outNum);
    }else{
        vector<string> newOut;
        int size = (int)out.size();
        for(int i = 0; i < size; i++){
            int count = (int)out[i].size();
            int targetIndex;
            for(int j = 0; j < count; j++){
                if(in[index - 1] == out[i][j]){
                    targetIndex = j;
                    break;
                }
            }
            string tmp(out[i]);
            for(int j = targetIndex; j <= count; j++){
                tmp.insert(tmp.begin() + j, in[index]);
                newOut.push_back(tmp);
                tmp.erase(tmp.begin() + j);
            }
        }
        swap(out, newOut);
    }
    helper(in, out, index+1);
}

vector<string> trainOut(string in){
    vector<string> result;
    int size = (int)in.length();
    if(size <= 0)
        return result;
    helper(in,result,0);
    sort(result.begin(),result.end());
    return result;
    
}

int main(int argc, const char * argv[]) {
    int n;
    while(cin>>n){
        string train = "";
        int index;
        for(int i = 0; i < n; i++){
            cin>>index;
            train += to_string(index);
        }
        
        vector<string> result = trainOut(train);
        
        for(int i = 0; i < result.size(); i++){
            for(int j = 0; j < result[i].size(); j++){
                if(j == 0)
                    cout<<result[i][j];
                else
                    cout<<" "<<result[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
