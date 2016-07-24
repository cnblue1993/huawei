//
//  main.cpp
//  成绩排序
//
//  Created by anne on 16/7/17.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct student{
    int index;
    int grade;
    string name;
};

bool asc(student a, student b){   //升序
    if(a.grade == b.grade)
        return a.index < b.index;
    else
        return a.grade < b.grade;
}

bool desc(student a, student b){  //降序
    if(a.grade == b.grade)
        return a.index < b.index;
    else
        return a.grade > b.grade;
}

int main(int argc, const char * argv[]) {
    int n,m;
    while(cin>>n>>m){
        vector<student> s(n);
        for(int i = 0; i < n; i++){
            s[i].index = i;
            cin>>s[i].name>>s[i].grade;
        }
        if(m == 0){
            sort(s.begin(), s.end(), desc);
        }else{
            sort(s.begin(), s.end(), asc);
        }
        for(int i = 0; i < n; i++){
            cout<<s[i].name<<" "<<s[i].grade<<endl;
        }
    }
    return 0;
}
