# Maximize Area of Square Hole in Grid

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/)

There is a grid with n + 2 horizontal bars and m + 2 vertical bars, and initially containing 1 x 1 unit cells.

The bars are 1-indexed.

You are given the two integers, n and m.

You are also given two integer arrays: hBars and vBars.
- hBars contains distinct horizontal bars in the range [2, n + 1].
- vBars contains distinct vertical bars in the range [2, m + 1].

You are allowed to remove bars that satisfy any of the following conditions:
- If it is a horizontal bar, it must correspond to a value in hBars.
- If it is a vertical bar, it must correspond to a value in vBars.

Return an integer denoting the maximum area of a square-shaped hole in the grid after 
removing some bars (possibly none).

### Sample Input
```
n = 2, m = 1, hBars = [2,3], vBars = [2]
```

### Sample Output
```
4

Explanation: 
The left image shows the initial grid formed by the bars.
The horizontal bars are in the range [1,4], and the vertical bars are in the range [1,3].
It is allowed to remove horizontal bars [2,3] and the vertical bar [2].
One way to get the maximum square-shaped hole is by removing horizontal bar 2 and vertical bar 2.
The resulting grid is shown on the right.
The hole has an area of 4.
It can be shown that it is not possible to get a square hole with an area more than 4.
Hence, the answer is 4.
 
```

### Solution
```cpp
class Solution {
public:
    int findMaxConsecutiveBars(vector<int>& nums){
        unordered_map<int, int> mpp;
        int maxLen = 1;
        for(auto it: nums){
            if(mpp.find(it-1) != mpp.end()){
                mpp[it] = mpp[it-1] + 1;
                maxLen = max(mpp[it], maxLen);
            }
            else mpp[it] = 1;
        }
        return maxLen;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        
        int maxLen = findMaxConsecutiveBars(hBars);
        int maxWidth = findMaxConsecutiveBars(vBars);
        
        int dimensions = min(maxLen, maxWidth) + 1;
        return dimensions*dimensions;
    }
};
```
