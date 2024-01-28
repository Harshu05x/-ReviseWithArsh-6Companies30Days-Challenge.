# Short Encoding of Words

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/short-encoding-of-words/description/)

A valid encoding of an array of `words` is any reference string `s` and array of `indices` indices such that:
- `words.length == indices.length`
- The reference string `s` ends with the `'#'` character.  
- For each index `indices[i]`, the substring of `s` starting from `indices[i]` and up to (but not including) the next
  '#' character is equal to words[i].

Given an array of `words`, return the length of the shortest reference string `s` possible of any valid encoding of words.

### Sample Input
```
words = ["time", "me", "bell"]
```

### Sample Output
```
10

Explanation: A valid encoding would be s = "time#bell#" and indices = [0, 2, 5].
words[0] = "time", the substring of s starting from indices[0] = 0 to the next '#' is underlined in "time#bell#"
words[1] = "me", the substring of s starting from indices[1] = 2 to the next '#' is underlined in "time#bell#"
words[2] = "bell", the substring of s starting from indices[2] = 5 to the next '#' is underlined in "time#bell#"
 
```

### Solution
```cpp
class Solution {
public:
    static bool compare (string& first, string& second) {
        return first.size() > second.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<string, int> mp;
        int ans = 0;
        
        sort(words.begin(), words.end(), compare);

        for(int i=0; i<words.size(); i++){
            mp[words[i]]++;
        }
        
        for(int i=0; i<words.size(); i++){
            int k = words[i].size();
            if(mp[words[i]] >0){
                ans += (k+1);
            }
            
            for(int j=k-1; j>=0; j--){
                string s = words[i].substr(j, k-j);
                mp[s] = 0;
            }
        }
        return ans;
    }
};
```
