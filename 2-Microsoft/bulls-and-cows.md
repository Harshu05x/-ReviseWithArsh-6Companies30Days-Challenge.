# Bulls and Cows

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/bulls-and-cows/description/)

You are playing the `Bulls and Cows` game with your friend.

You write down a secret number and ask your friend to guess what the number is. 
When your friend makes a guess, you provide a hint with the following info:
- The number of `"bulls"`, which are digits in the guess that are in the `correct position`.
- The number of `"cows"`, which are digits in the guess that are `in your secret` number but are located in the `wrong position`.
Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.

Given the `secret` number secret and your friend's guess `guess`, return the hint for your friend's guess.
The hint should be formatted as `"xAyB"`, where `x` is the number of `bulls` and `y` is the number of cows. 
Note that both secret and guess may contain duplicate digits.

### Sample Input
```
secret = "1807", guess = "7810"
```

### Sample Output
```
"1A3B"
```

### Solution
```cpp
class Solution {
public:
    string getHint(string s, string g) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        int samePlaceCnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == g[i])
                samePlaceCnt++;
            else{
                mp1[s[i]]++;
                mp2[g[i]]++;
            }
        }

        int sameCnt = 0;
        for(auto i: mp1){
            sameCnt += min(mp1[i.first],mp2[i.first]);
        }
        
        return to_string(samePlaceCnt) + "A" + to_string(sameCnt) + "B";
    }
};
```
