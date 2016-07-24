//
//  main.cpp
//  Sudoku
//
//  Created by anne on 16/6/9.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void shudu(vector<vector<int>> &num, int r, bool &finish){
    if(finish || r > 8){
        return;
    }
    
    bool find = false;
    int row = r;
    int col = 0;
    for(int i = r; i < 9 && !find; i++){
        for(int j = 0; j < 9; j++){
            if(num[i][j] == 0){
                row = i;
                col = j;
                find = true;
                break;
            }
        }
    }
    
    if(find){
        vector<bool> used(10, false);
        for(int i = 0; i < 9; i++){
            used[num[row][i]] = true;
            used[num[i][col]] = true;
        }
        
        int x = row / 3;
        int y = col / 3;
        for(int i = x * 3; i < (x + 1) * 3; i++){
            for(int j = y * 3; j < (y + 1) * 3; j++){
                used[num[i][j]] = true;
            }
        }
        
        for(int i = 0; i < 10; i++){
            if(!used[i]){
                num[row][col] = i;
                used[i] = true;
                shudu(num, row, finish);
                if(finish)
                    return;
                num[row][col] = 0;
                used[i] = false;
            }
        }
    }else{
        finish = true;
        return;
    }
    
}

void print(vector<vector<int>> num){
    int n = (int)num.size();
    int m = (int)num[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m-1; j++)
            cout<<num[i][j]<<" ";
        cout<<num[i][m-1]<<endl;
    }
}

int main(int argc, const char * argv[]) {
    while(true){
        vector<vector<int>> num(9,  vector<int> (9,-1));
        bool finish = false;
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                
                cin>>num[i][j];
                if(num[i][j] == EOF){
                    return 0;
                }
            }
        }
        
        shudu(num,0,finish);
        
        print(num);
    }
    return 0;
}
