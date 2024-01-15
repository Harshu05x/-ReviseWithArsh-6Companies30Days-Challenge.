# Extra Characters in a String

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/extra-characters-in-a-string/description/)

You are given a 0-indexed string `s` and a `dictionary` of words dictionary. You have to break s into 
one or more `non-overlapping` substrings such that each substring is present in dictionary. There may be some 
`extra characters` in s which are not present in any of the substrings.

Return the minimum number of extra characters left over if you break up s optimally.

### Sample Input
```
s = "sayhelloworld", dictionary = ["hello","world"]
```

### Sample Output
```
 3

Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12.
The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters.
Hence, we return 3.
```

### Solution 1
```cpp
class Solution {
    unordered_map<string,int> mp;
    int recursive(string& s, int i, int j,  vector<vector<int>>& dp){ 
        if(j >= s.size())
            return j-i;

        if(dp[i][j] != -1)
            return dp[i][j];

        string temp = s.substr(i,j-i+1);

        int include = 1e9, exclude = 1e9, skip = 1e9;
        if(mp.find(temp) != mp.end())
            include = recursive(s,j+1,j+1,dp);
        
        exclude = recursive(s,i,j+1,dp);

        skip = j-i+1 + recursive(s,j+1,j+1,dp);

        return dp[i][j] = min(include,min(exclude,skip));
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        for(auto word:dictionary){
            mp[word]++;
        }
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return recursive(s,0,0,dp);
    }
};
```

### Solution 2
```cpp
class Solution {
    unordered_map<string,int> mp;
    int bottomUp(string s){
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i = 0; i <= n; i++){
            dp[i][n] = n-i;
        }

        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                string temp = s.substr(i,j-i+1);

                int include = 1e9, exclude = 1e9, skip = 1e9;

                if(mp.find(temp) != mp.end())
                    include = dp[j+1][j+1];
                
                exclude = dp[i][j+1];

                skip = j-i+1 + dp[j+1][j+1];

                dp[i][j] = min(include,min(exclude,skip));
            }
        }
        return dp[0][0];
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        for(auto word:dictionary){
            mp[word]++;
        }
        return bottomUp(s);
    }

};
```
