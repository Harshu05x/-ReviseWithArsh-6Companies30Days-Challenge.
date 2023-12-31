# Combination Sum  

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/combination-sum-iii/)

Find all `valid combinations of k numbers that sum up to n` such that the following conditions are true:
- Only numbers 1 through 9 are used.
- Each number is used at most once.

Return a list of all possible valid combinations. 
The list must not contain the same combination twice, and the combinations may be returned in any order.

### Sample Input
```
k = 3, n = 9
```
### Sample Output
```
[[1,2,6],[1,3,5],[2,3,4]]
```

### Solution
```cpp

class Solution {
public:
    vector<vector<int>> ans;
    void findCombinationSum(int& k, int n, vector<int>& temp, int index){
        if(temp.size() == k){
            if(n == 0) ans.push_back(temp);
            return;
        }

        for(int i = index; i <= 9; i++){
            if(i <= n){
                temp.push_back(i);
                findCombinationSum(k,n-i,temp,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        int sum = 0;
        int index = 0;

        findCombinationSum(k,n,temp,1);

        return ans;
    }
};
```
