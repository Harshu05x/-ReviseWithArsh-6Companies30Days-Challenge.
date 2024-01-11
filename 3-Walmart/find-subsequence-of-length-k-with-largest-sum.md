# Find Subsequence of Length K With the Largest Sum

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/)

You are given an integer array `nums` and an integer `k`. You want to find a subsequence of nums of length `k` that has the `largest sum`.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing 
the order of the remaining elements.

### Sample Input
```
 nums = [-1,-2,3,4], k = 3
```

### Sample Output
```
[-1,3,4]

Explanation: 
The subsequence has the largest sum of -1 + 3 + 4 = 6.
```

### Solution
```cpp
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> temp;
        
        int n = nums.size();
        for(int i = 0; i < n; i++){
            temp.push_back({nums[i],i});
        }

        sort(temp.begin(),temp.end());
        vector<pair<int,int>> ans;

        for(int i = n-1; i >= n-k; i--){
            ans.push_back({temp[i].second,temp[i].first});
        }

        sort(ans.begin(),ans.end());

        vector<int> finalAns;
        for(auto i: ans)
            finalAns.push_back(i.second);  
        
        return finalAns;
    }   
};
```
