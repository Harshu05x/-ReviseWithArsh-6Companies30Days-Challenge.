# Largest Divisible Subset

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/largest-divisible-subset/)

Given a set of distinct positive integers `nums`, return the largest subset `answer` such that every pair 
`(answer[i], answer[j])` of elements in this subset satisfies:
- `answer[i] % answer[j] == 0`, or
- `answer[j] % answer[i] == 0`
  
If there are multiple solutions, return any of them.

### Sample Input
```
nums = [1,2,3]
```

### Sample Output
```
[1,2]

Explanation: [1,3] is also accepted.
```

### Solution
```cpp
class Solution {
vector<int> printLDS(vector<int>& arr){
    int n = arr.size();
    vector<int>dp(n,1);
    vector<int>hash(n,-1);

    int ans = 1;
    int LDS_ind = -1;
    for(int index = 0; index < n; index++){
        for(int prevIndex = 0; prevIndex < index; prevIndex++){
            if(arr[index] % arr[prevIndex] == 0){
                if(1+dp[prevIndex] > dp[index]){
                    dp[index] = 1+dp[prevIndex];
                    hash[index] = prevIndex;
                }
            }
        }
        if(ans <= dp[index]){
            ans = dp[index];
            LDS_ind = index;
        }
    }
    vector<int> ansVec;
    while(LDS_ind != -1){
        ansVec.push_back(arr[LDS_ind]);
        LDS_ind = hash[LDS_ind];
    }
    return ansVec;
}
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> ans = printLDS(arr);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```
