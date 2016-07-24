//
//  main.cpp
//  字典序排列
//
//  Created by anne on 16/5/5.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool cmpString(string a, string b){
    int len1 = (int)a.length();
    int len2 = (int)b.length();
    int i,j;
    for(i=0,j=0; i<len1 && j<len2; i++,j++){
        if(a[i] > b[j])
            return true;
        else if(a[i] < b[j])
            return false;
        else
            continue;
    }
    if(i == len1 && j != len2)
        return false;
    else
        return true;
    
}

void quickSort(vector<string> &words, int left, int right){
    int oldLeft = left;
    int oldRight = right;
    bool flag = true;
    string baseArr = words[oldLeft];
    while (left < right){
        while (left < right && cmpString(words[right], baseArr)){
            right--;
            flag = false;
        }
        words[left] = words[right];
        while (left < right && cmpString(baseArr, words[left])){
            left++;
            flag = false;
        }
        words[right] = words[left];
    }
    words[left] = baseArr;
    if (!flag){
        quickSort(words, oldLeft, left-1);
        quickSort(words, left+1, oldRight);
    }
}


int main(int argc, const char * argv[]) {

    int n;
    string s;
    while(cin>>n){
        vector<string> words;
        for(int i = 0; i < n; i++){
            cin>>s;
            words.push_back(s);
        }
        quickSort(words, 0, n-1);
        for(string x:words){
            cout<<x<<endl;
        }
    }
    return 0;
}
