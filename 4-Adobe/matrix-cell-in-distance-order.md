# Matrix Cells in Distance Order

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/matrix-cells-in-distance-order/description/)

You are given four integers `row, cols, rCenter, and cCenter`. 
There is a `rows x cols` matrix and you are on the cell with the coordinates `(rCenter, cCenter)`.

Return the coordinates of all cells in the matrix, sorted by their distance from (rCenter, cCenter) 
from the smallest distance to the largest distance. You may return the answer in any order that satisfies this condition.

The distance between two cells `(r1, c1)` and `(r2, c2)` is `|r1 - r2| + |c1 - c2|`.

### Sample Input
```
 rows = 2, cols = 2, rCenter = 0, cCenter = 1
```

### Sample Output
```
[[0,1],[0,0],[1,1],[1,0]]

Explanation:
The distances from (0, 1) to other cells are: [0,1,1,2]
The answer [[0,1],[1,1],[0,0],[1,0]] would also be accepted as correct.
```

### Solution
```cpp
class Solution {
    vector<vector<int>> bfs(int m, int n, int x, int y){
        vector<vector<int>> ans;
        queue<pair<int,int>> que;
        map<pair<int,int>,bool> vis;

        que.push({x,y});
        vis[{x,y}] = true;

        while(!que.empty()){
            auto front = que.front();
            que.pop();
            x = front.first;
            y = front.second;
            ans.push_back({x,y});

            int dx[] = {-1,1,0,0};
            int dy[] = {0,0,-1,1};

            for(int i = 0; i < 4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX >= 0 && newX < m && newY >= 0 
                    && newY < n && !vis[{newX,newY}]){
                        vis[{newX,newY}] = true;
                        que.push({newX,newY});
                    }
            }
        }
        return ans;
    }
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        return bfs(rows,cols,rCenter,cCenter);
    }
};
```
