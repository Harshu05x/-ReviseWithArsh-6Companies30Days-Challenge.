# Minimum Moves to Equal Array Elements II

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/)

Given an integer array `nums` of size `n`, return the minimum number of moves required to make all array elements equal.

In one move, you can `increment` or `decrement` an element of the array `by 1`.

Test cases are designed so that the answer will fit in a 32-bit integer.

### Sample Input
```
nums = [1,2,3]
```

### Sample Output
```
2

Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
```

### Solution 1
```cpp
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int n = nums.size();
        int median = n/2;
        for(int i = 0; i < nums.size(); i++){
            ans += abs(nums[i]-nums[median]);          
        }
        return ans;
    }
};
```

### Solution 2
```cpp
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        long long ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            long long sum = 0;
            for(int j = 0; j < nums.size(); j++){
                if(i != j){
                    sum += abs(nums[i]-nums[j]);
                }

            }
            ans = min(ans,sum);
        }
        return ans;
    }
};
```
