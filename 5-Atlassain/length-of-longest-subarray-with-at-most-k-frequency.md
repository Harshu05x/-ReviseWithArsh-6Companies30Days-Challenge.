# Length of Longest Subarray With at Most K Frequency

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/)

You are given an integer array nums and an integer k.

The frequency of an element x is the number of times it occurs in an array.

An array is called good if the frequency of each element in this array is less than or equal to k.

Return the length of the longest good subarray of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

### Sample Input
```
nums = [1,2,3,1,2,3,1,2], k = 2
```

### Sample Output
```
6

Explanation: The longest possible good subarray is [1,2,3,1,2,3] since the 
values 1, 2, and 3 occur at most twice in this subarray. Note that the subarrays [2,3,1,2,3,1] and [3,1,2,3,1,2] 
are also good.It can be shown that there are no good subarrays with length more than 6.
 
```

### Solution
```cpp
class Solution{
public:
    int maxSubarrayLength(vector<int> &nums, int k){
        int l = 0;
        int j = 0;
        int n = nums.size();
        int mx = 0;
        map<int, int> mp;

        for (int i = 0; i < n; i++){
            mp[nums[i]]++;
        
            while(mp[nums[i]]>k){
                mp[nums[j]]--;
                j++;
            }
            mx = max(mx,i-j+1);
        }
        return mx;
    }
};
```
