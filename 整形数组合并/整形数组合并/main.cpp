//
//  main.cpp
//  整形数组合并
//
//  Created by anne on 16/7/18.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void CombineBySort(vector<int> arr1, vector<int> arr2){
    
    int n = (int)arr1.size();
    int m = (int)arr2.size();
    vector<int> result(n+m);
    int i = 0, j = 0;
    
    int min = 0;
    int pre = INT16_MAX;
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    int k = 0;
    while(i < n && j < m){
        if(arr1[i] <= arr2[j]){
            min = arr1[i++];
        }else{
            min = arr2[j++];
        }
        if(min == pre)
            continue;
        else{
            result[k++] = min;
            pre = min;
        }
    }
    while(i != n){
        result[k++] = arr1[i++];
    }
    while(j != m){
        result[k++] = arr2[j++];
    }
    
    for(i = 0; i < k; i++)
        cout<<result[i];
}

int main(int argc, const char * argv[]) {
    int n,m;
    while(cin>>n){
        vector<int> arr1(n);
        int i = 0;
        while (n--) {
            cin>>arr1[i++];
        }
        
        cin>>m;
        vector<int> arr2(m);
        i = 0;
        while (m--) {
            cin>>arr2[i++];
        }
        
        CombineBySort(arr1, arr2);
        
    }
    return 0;
}

////用map存储，自然是升序。
//#include<iostream>
//#include<map>
//using namespace std;
//
//int main(){
//    int n1,n2;
//    while(cin>>n1){
//        int i;
//        int num;
//        map<int, int>m;
//        for(i=0; i<n1; i++){
//            cin>>num;
//            m[num]++;
//        }
//        cin>>n2;
//        for(i = 0; i< n2; i++){
//            cin>>num;
//            m[num]++;
//        }
//        map<int,int>::iterator it = m.begin();
//        while(it!=m.end()){
//            cout<<it->first;
//            ++it;
//        }
//    }
//    return 0;
//}
