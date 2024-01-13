# Battleships in a Board

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/battleships-in-a-board/description/)

Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 
1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell 
separates between two battleships (i.e., there are no adjacent battleships).


### Sample Input
```
board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
```
![image](https://github.com/Harshu05x/ReviseWithArsh-6Companies30Days-Challenge/assets/96901785/93734ba1-6c03-450e-b4ad-e3558277d408)

### Sample Output
```
2
```

### Solution
```cpp
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        map<pair<int,int>,bool> mp;
        int m = board.size();
        int n = board[0].size();

        int cnt = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mp.find({i,j}) == mp.end() && board[i][j] == 'X'){
                    cnt++;
                    mp[{i,j}] = true;

                    // column traverse
                    int k = i-1;
                    while(k >= 0 && board[k][j] != '.'){
                        mp[{k,j}] = true;
                        k--;
                    }
                    k = i+1;
                    while(k < m && board[k][j] != '.'){
                        mp[{k,j}] = true;
                        k++;
                    }

                    // row travarse
                    k = j-1;
                    while(k >= 0 && board[i][k] != '.'){
                        mp[{i,k}] = true;
                        k--;
                    }
                    k = j+1;
                    while(k < n && board[i][k] != '.'){
                        mp[{i,k}] = true;
                        k++;
                    }
                }
            }
        }
        return cnt;
    }
};
```
