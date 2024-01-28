# Special Permutations

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)]([https://leetcode.com/problems/constrained-subsequence-sum/](https://leetcode.com/problems/special-permutations/description/))

You are given a 0-indexed integer array `nums` containing `n` distinct positive integers. A permutation of `nums` is called special if:
For all indexes `0 <= i < n - 1`, either `nums[i] % nums[i+1] == 0` or `nums[i+1] % nums[i] == 0`.

Return the total number of special permutations. As the answer could be large, return it modulo 109 + 7.

### Sample Input
```
nums = [2,3,6]
```

### Sample Output
```
 2

Explanation: [3,6,2] and [2,6,3] are the two special permutations of nums.
```

### Solution
```cpp
class Solution
{
    int mod = 1e9 + 7, n, dp[16385][16];
    int rec(vector<int> &v, int cnt, int i, int mask)
    {
        if (cnt == n)
            return 1;
        if (dp[mask][i + 1] != -1)
            return dp[mask][i + 1];
        
        int res = 0;
        for (int j = 0; j < n; j++)
            if (i == -1 || ((mask & (1 << j)) == 0 && i != j && (v[i] % v[j] == 0 || v[j] % v[i] == 0)))
                (res += rec(v, cnt + 1, j, mask | (1 << j))) %= mod;
        return dp[mask][i + 1] = res;
    }

public:
    int specialPerm(vector<int> &v)
    {
        n = v.size();
        memset(dp, -1, sizeof(dp));
        return rec(v, 0, -1, 0);
    }
};
```
