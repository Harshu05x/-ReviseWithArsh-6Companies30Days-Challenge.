# Count the Number of Incremovable Subarrays I

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/description/)

You are given a 0-indexed array of positive integers nums.

A subarray of nums is called `incremovable if nums becomes strictly increasing on removing the subarray`. 
For example, the subarray [3, 4] is an incremovable subarray of [5, 3, 4, 6, 7] because removing this subarray 
changes the array [5, 3, 4, 6, 7] to [5, 6, 7] which is strictly increasing.

Return the total number of incremovable subarrays of nums.

Note that an empty array is considered strictly increasing.

A subarray is a contiguous non-empty sequence of elements within an array.

### Sample Input
```
 nums = [6,5,7,8]
```

### Sample Output
```
7

Explanation:
The 7 incremovable subarrays are: [5], [6], [5,7], [6,5], [5,7,8], [6,5,7] and [6,5,7,8].
It can be shown that there are only 7 incremovable subarrays in nums.
```

### Solution
```cpp
class Solution {
    bool isIncreasing(vector<int>& temp){
        for(int i = 1; i < temp.size(); i++)
            if(temp[i] <= temp[i-1]) return false;
        return true;
    }
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                vector<int> temp;
                for(int k = 0; k < i; k++)
                    temp.push_back(nums[k]);
                for(int k = j+1; k < n; k++)
                    temp.push_back(nums[k]);
                if(isIncreasing(temp))
                    ans++;
            }
        }
        return ans;
    }
};
```
