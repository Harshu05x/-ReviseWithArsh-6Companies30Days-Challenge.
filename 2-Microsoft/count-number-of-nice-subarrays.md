# Count Number of Nice Subarrays

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/count-number-of-nice-subarrays/description/)

Given an array of integers `nums` and an integer k. 
A continuous subarray is called `nice` if there are `k odd numbers` on it.

Return the number of nice sub-arrays.

### Sample Input
```
 nums = [1,1,2,1,1], k = 3
```

### Sample Output
```
2

Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
```

### Solution
```cpp
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int oddCnt = 0;
        int cnt = 0;

        for(auto i: nums){
            if(i & 1)
                oddCnt++;
            if(oddCnt == k)
                cnt++;
                
            if(mp.find(oddCnt-k) != mp.end())
                cnt += mp[oddCnt-k];
            if(mp.find(oddCnt) != mp.end())
                mp[oddCnt]++;
            else 
                mp[oddCnt] = 1;
        }
        return cnt;
    }
};
```
