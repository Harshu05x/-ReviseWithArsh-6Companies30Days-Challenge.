# Number of Ways to Reach a Position After Exactly k Steps

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/description/)

You are given two `positive` integers `startPos` and `endPos`. Initially, you are standing at position startPos on an infinite number line. 
With one step, you can move either `one position to the left, or one position to the right`.
Given a positive integer k, return the number of different ways to reach the position endPos starting from startPos, such that you `perform exactly k steps`. 
Since the answer may be very large, return it modulo 109 + 7.
Two ways are considered different if the order of the steps made is not exactly the same.
`Note` that the number line includes negative integers.

### Sample Input
```
startPos = 1, endPos = 2, k = 3
```
### Sample Output
```
3

Explanation: We can reach position 2 from 1 in exactly 3 steps in three ways:
- 1 -> 2 -> 3 -> 2.
- 1 -> 2 -> 1 -> 2.
- 1 -> 0 -> 1 -> 2.
It can be proven that no other way is possible, so we return 3.
```

### Solution
```cpp
class Solution {
#define mod 1000000007
public:
    int recursive(int s, int e, int k, map<pair<int,int>,int>& mp) {
        if(k == 0){
            if(s == e)
                return 1;
            return 0;
        }
        if(e-s == k || s-e == k)
            return 1;

        if(mp.find({s,k}) != mp.end())
            return mp[{s,k}];
        
        int plus = recursive(s+1,e,k-1,mp);
        int minus = recursive(s-1,e,k-1,mp);

        return mp[{s,k}] = (plus % mod + minus % mod) % mod;
    }
    
    int numberOfWays(int s, int e, int k) {
        map<pair<int,int>,int> mp;
        return recursive(s,e,k,mp);
    }
};
```
