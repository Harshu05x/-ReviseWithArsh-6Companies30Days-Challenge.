#  Longest Word in Dictionary through Deleting

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/)

Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by
deleting some of the given string characters. If there is more than one possible result, return the longest word
with the smallest lexicographical order. If there is no possible result, return the empty string.

### Sample Input
```
s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
```
### Sample Output
```
"apple"
```

### Solution
```cpp
class Solution {
public:
      bool isSubsequence(string sub, string super){
        int i = 0, j = 0;
        while(i < sub.size() && j < super.size()){
            if(sub[i] == super[j])
                i++;
            j++;
        }
        return i == sub.size();
    };
    
    string findLongestWord(string s, vector<string>& d) {
        string ans = "";
        for(string& word : d)
        {
            if(word.size() > ans.size() || (word.size() == ans.size() && word < ans)){
                if(isSubsequence(word, s))
                    ans = word;
            }
        }
        return ans;
    }
};
```
