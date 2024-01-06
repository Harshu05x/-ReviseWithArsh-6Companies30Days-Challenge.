# Repeated DNA Sequences

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/repeated-dna-sequences/description/)

The `DNA sequence` is composed of a series of nucleotides abbreviated as `'A'`, `'C'`, `'G'`, and `'T'`.
- For example, "ACGAATTCCG" is a DNA sequence.
  
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the `10-letter-long sequences` (substrings) 
that `occur more than once` in a DNA molecule. 
You may return the answer in any order.

### Sample Input
```
s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
```

### Sample Output
```
["AAAAACCCCC","CCCCCAAAAA"]
```

### Solution
```cpp
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() <= 10)
            return {};

        unordered_map<string,int> mp;

        for(int i = 0; i <= s.size()-10; i++){
            string str = s.substr(i,10);
            mp[str]++;
        }

        vector<string> ans;
        for(auto i: mp){
            if(i.second > 1)
                ans.push_back(i.first);
        }
        return ans;
    }
};
```
