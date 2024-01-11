# Word Break

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/word-break/)

Given a string `s` and a `dictionary` of strings wordDict, return `true` if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

### Sample Input
```
s = "applepenapple", wordDict = ["apple","pen"]
```

### Sample Output
```
true

Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
```

### Solution
```cpp
class Solution {
public:
bool topDownWordBreak(string& str, vector<string>& dict, int i, vector<int>& dp, 
    unordered_map<string,bool>& mp){
    
    if(i >= str.size())
        return true;

    if(dp[i] != -1)
        return dp[i];

    string s = "";
    bool ans = false;
    for(int j = i; j < str.size(); j++){
        s.push_back(str[j]);
        if(mp[s]){
            ans |= topDownWordBreak(str,dict,j+1,dp,mp);
        }
    }
    return dp[i] = ans;
}
    bool wordBreak(string s, vector<string>& dict) {
        unordered_map<string,bool> mp;
        for(auto s : dict)
            mp[s] = true;
        vector<int> dp(s.size(),-1);
        return topDownWordBreak(s,dict,0,dp,mp);
    }
};
```
