# Construct the Longest New String

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/construct-the-longest-new-string/description/)

You are given three integers `x, y, and z`.

You have `x` strings equal to `"AA"`, `y` strings equal to `"BB"`, and `z` strings equal to `"AB"`. 
You want to choose some (possibly all or none) of these strings and `concatenate them` in some order to form a new string. 
This new string must not contain `"AAA"` or `"BBB"` as a substring.

Return the maximum possible length of the new string.

A substring is a contiguous non-empty sequence of characters within a string.

### Sample Input
```
x = 3, y = 2, z = 2
```

### Sample Output
```
14

Explanation:
We can concactenate the strings "AB", "AB", "AA", "BB", "AA", "BB", and "AA" in that order.
Then, our new string is "ABABAABBAABBAA". 
That string has length 14, and we can show that it is impossible to construct a string of longer length.
 
```

### Solution
```cpp
class Solution {
public:
    int longestString(int x, int y, int z) {
        
        int ans = 0;
        int k = min(x,y);

        ans += 4 * k;      

        x -= k;
        y -= k;

        ans += 2 *z;

        if(x > 0 || y > 0)
            ans += 2;
        
        return ans;
    }
};
```
