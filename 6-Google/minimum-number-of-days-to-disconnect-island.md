# Minimum Number of Days to Disconnect Island

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/description/)

You are given an m x n binary grid grid where 1 represents land and 0 represents water. 
An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.

The grid is said to be connected if we have exactly one island, otherwise is said disconnected.

In one day, we are allowed to change any single land cell (1) into a water cell (0).

Return the minimum number of days to disconnect the grid.

### Sample Input
```
grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
```

### Sample Output
```
2

Explanation: We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.
```

### Solution
```cpp
class Solution {
public:
    bool valid(int x, int y, int n, int m) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }
    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& vis,
             int n, int m) {
        vis[x][y] = 1;
        int deli[] = {0, 0, 1, -1};
        int delj[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int newi = x + deli[i];
            int newj = y + delj[i];
            if (valid(newi, newj, n, m) && vis[newi][newj] == 0 &&
                grid[newi][newj] == 1) {
                dfs(newi, newj, grid, vis, n, m);
            }
        }
    }
    bool disconnected(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0)
                    continue;
                if (vis[i][j] == 0)
                    cnt++;
                if (cnt > 1)
                    return true;
                dfs(i, j, grid, vis, n, m);
            }
        }
        if (cnt == 0)
            return true;
        return false;
    }
    int minDays(vector<vector<int>>& grid) {
        if (disconnected(grid))
            return 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0)
                    continue;
                grid[i][j] = 0;
                if (disconnected(grid))
                    return 1;
                grid[i][j] = 1;
            }
        }
        return 2;
    }
};
```
