# Assign Cookies

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/assign-cookies/description/)

Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child `i` has a greed factor `g[i]`, which is the minimum size of a `cookie` that the child will be content with; and each cookie `j` has 
a size s[j]. If `s[j] >= g[i],` we can assign the cookie j to the child i, and the child i will be content.

### Sample Input
```
g = [1,2], s = [1,2,3]
```

### Sample Output
```
2

Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.
 
```

### Solution
```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        vector<int> nxt(s.size()+1,0), curr(s.size()+1,0);
        
        for(int i = g.size()-1; i >= 0; i--){
            for(int j = s.size()-1; j >= 0; j--){
                int include = 0;
                if(s[j] >= g[i])
                    include = 1 + nxt[j+1];
                int exclude = 0 + max(nxt[j],curr[j+1]);

                curr[j] = max(include,exclude);
            }
            nxt = curr;
        }
        return nxt[0];
    }
};
```
