# K-diff Pairs in an Array

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/k-diff-pairs-in-an-array/description/)

Given an array of integers `nums` and an integer `k`, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair `(nums[i], nums[j])`, where the following are true:
- `0 <= i, j < nums.length`
- `i != j`
- `|nums[i] - nums[j]| == k`
  
Notice that |val| denotes the absolute value of val.

### Sample Input
```
 nums = [3,1,4,1,5], k = 2
```

### Sample Output
```
2

Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
```

### Solution
```cpp
class Solution {
public:
    int findPairs(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int i = 0, j = 1;
        set<pair<int,int>> ans;
        while(j < arr.size()){
            int diff = arr[j] - arr[i];
            if(diff == k){
                ans.insert({arr[i],arr[j]});
                i++; j++;
            }
            else if(diff > k){
                i++;
            }
            else j++;
            if(i == j) j++;
        }
        return ans.size();   
    } 
};
```
