# Map of Highest Peak

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/map-of-highest-peak/description/)

You are given an integer matrix `isWater` of size `m x n` that represents a map of **land** and **water** cells.

- If `isWater[i][j] == 0`, cell `(i, j)` is a `land` cell.
- If `isWater[i][j] == 1`, cell `(i, j)` is a `water` cell.

You must assign each cell a height in a way that follows these rules:

- The height of each cell must be non-negative.
- If the cell is a water cell, its height must be 0.
- Any two adjacent cells must have an **absolute height difference of at most 1**. 
A cell is adjacent to another cell if the former is directly **north, east, south, or west** of the latter (i.e., their sides are touching).

Find an assignment of heights such that the maximum height in the matrix is maximized.
Return an integer matrix `height` of size `m x n` where `height[i][j`] is cell `(i, j)'s height`. 
If there are multiple solutions, return any of them.

### Sample Input
```
isWater = [[0,0,1],[1,0,0],[0,0,0]]
```
### Sample Output
```
 [[1,1,0],[0,1,1],[1,2,2]]
```

### Solution
```cpp
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> arr = isWater;
        queue<pair<pair<int,int>,int>> que;

        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < arr[i].size(); j++){
                bool flag = false;
                if(arr[i][j] == 1){
                    que.push({{i,j},0});
                    flag = true;
                }
                if(flag) arr[i][j] = 0;
                else arr[i][j] = -1;
            }
        }


        while(!que.empty()){
            auto fnode = que.front();
            que.pop();
            int x = fnode.first.first;
            int y = fnode.first.second;
            int h = fnode.second;

            int dx[] = {-1,1,0,0};
            int dy[] = {0,0,-1,1};

            for(int i = 0; i < 4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX >= 0 && newX < arr.size() && newY >= 0 && newY < arr[0].size()
                    && arr[newX][newY] == -1 && arr[newX][newY] != 0){
                    arr[newX][newY] = h+1;
                    que.push({{newX,newY},h+1});
                }
            }
        }
        return arr;
    }
};
```
