# Get Equal Substrings Within Budget

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/get-equal-substrings-within-budget/description/)

You are given two strings s and t of the same length and an integer maxCost.

You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., 
the absolute difference between the ASCII values of the characters).

Return the maximum length of a substring of s that can be changed to be the same as the corresponding 
substring of t with a cost less than or equal to maxCost. If there is no substring from s that can be changed to 
its corresponding substring from t, return 0.

### Sample Input
```
s = "abcd", t = "bcdf", maxCost = 3
```

### Sample Output
```
3

Explanation: "abc" of s can change to "bcd".
That costs 3, so the maximum length is 3.
```

### Solution
```cpp
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        
        int ans = 0;
        int j = 0;
        int maxi = 0;
        for(int i = 0; i < n; i++){
            maxi += abs(s[i] - t[i]);
            
            while(j <= i && maxi > maxCost){
                maxi -= abs(s[j]-t[j]);
                j++;
            }
            ans = max(i-j+1,ans);
        }
        return ans;
    }
};
```
