# Wiggle Sort II

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/wiggle-sort-ii/description/)

Given an integer array `nums`, reorder it such that `nums[0] < nums[1] > nums[2] < nums[3]....`

You may assume the input array always has a valid answer.

### Sample Input
```
 nums = [1,5,1,1,6,4]
```

### Sample Output
```
[1,6,1,5,1,4] or [1,4,1,5,1,6] both will be accepted.
```

### Solution
```cpp
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        int n = nums.size();
        
        int i = 1, j = n-1;
        while(i < n){
            nums[i] = temp[j];
            j--;
            i += 2;
        }

        i = 0;
        while(i < n){
            nums[i] = temp[j];
            j--;
            i += 2;
        }

    }
};
```
