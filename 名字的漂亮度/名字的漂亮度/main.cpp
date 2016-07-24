//
//  main.cpp
//  名字的漂亮度
//
//  Created by anne on 16/6/21.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void quickSort(vector<int> &nums, int left, int right){
    int oldLeft = left;
    int oldRight = right;
    bool flag = true;
    
    int index = arc4random_uniform(right - left + 1) + left;
    swap(nums[index], nums[oldLeft]);
    
    int base = nums[oldLeft];
    
    while (left < right) {
        while (left < right && nums[right] <= base) {
            right--;
            flag = false;
        }
        nums[left] = nums[right];
        while (left < right && nums[left] >= base) {
            left++;
            flag = false;
        }
        nums[right] = nums[left];
    }
    nums[left] = base;
    
    if(!flag){
        quickSort(nums, oldLeft, left - 1);
        quickSort(nums, left + 1, oldRight);
    }
}
void beauty(string name){
    vector<int> count(26,0);
    int sum = 0;
    long len = (long)name.length();
    if(len == 0){
        cout<<sum<<endl;
        return;
    }
    for(long i = 0; i < len; i++){
        if(name[i] >= 'a' && name[i] <='z')
            count[name[i] - 'a']++;
        else if(name[i] >= 'A' && name[i] <='Z')
            count[name[i] - 'A']++;
        else
            continue;
    }
    //sort(count.begin(),count.end(),cmp);
    quickSort(count, 0, 25);
    int max = 26;
    for(int i = 0; i < 26 && count[i]; i++){
        sum += count[i] *(max--);
    }
    cout<<sum<<endl;
}

int main(int argc, const char * argv[]) {
    int n;
    while(cin>>n){
        while (n--) {
            string name;
            cin>>name;
            beauty(name);
        }
        
    }
    return 0;
}
