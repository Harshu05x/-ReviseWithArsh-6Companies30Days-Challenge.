# Sum of Scores of Built Strings

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/sum-of-scores-of-built-strings/description/)

You are building a string s of length n one character at a time, prepending each new character 
to the front of the string. The strings are labeled from 1 to n, where the string with length i is labeled si.
- For example, for s = "abaca", s1 == "a", s2 == "ca", s3 == "aca", etc.
The score of si is the length of the longest common prefix between si and sn (Note that s == sn).

Given the final string s, return the sum of the score of every si.

### Sample Input
```
s = "babab"
```

### Sample Output
```
9

Explanation:
For s1 == "b", the longest common prefix is "b" which has a score of 1.
For s2 == "ab", there is no common prefix so the score is 0.
For s3 == "bab", the longest common prefix is "bab" which has a score of 3.
For s4 == "abab", there is no common prefix so the score is 0.
For s5 == "babab", the longest common prefix is "babab" which has a score of 5.
The sum of the scores is 1 + 0 + 3 + 0 + 5 = 9, so we return 9.
```

### Solution
```cpp
class Solution {
public:
    long long sumScores(string s) {
	    int n = s.size();
        long long result = 0;
        vector<int> z (n);
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r)
                z[i] = min (r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                ++z[i];
            if (i + z[i] - 1 > r)
                l = i,  r = i + z[i] - 1;
            result += z[i];
        }
        return result + s.size();
    }
};
```
