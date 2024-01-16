#  Find Players With Zero or One Losses

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/)

You are given an integer array `matches` where `matches[i] = [winneri, loseri]` indicates that the player 
`winneri` defeated player `loseri` in a match.

Return a list answer of size 2 where:
- `answer[0]` is a list of all players that have `not lost any matches`.
- `answer[1]` is a list of all players that have `lost exactly one match`.
- The values in the two lists should be returned in increasing order.

Note:
You should only consider the players that have played at least one match.
The testcases will be generated such that no two matches will have the same outcome.

### Sample Input
```
matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],
```

### Sample Output
```
[[1,2,10],[4,5,7,8]]

Explanation:
Players 1, 2, and 10 have not lost any matches.
Players 4, 5, 7, and 8 each have lost one match.
Players 3, 6, and 9 each have lost two matches.
Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].
 
```

### Solution
```cpp
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp;
        for(auto i: matches){
            int winner = i[0];
            int loser = i[1];
            if(mp.find(winner) == mp.end())
                mp[winner] = 0;
            mp[loser]++;
        }

        vector<int> winner,loser;
        for(auto i: mp){
            if(i.second == 0)
                winner.push_back(i.first);
            else if(i.second == 1)
                loser.push_back(i.first);
        }
        
        return {winner,loser};
    }
};
```
