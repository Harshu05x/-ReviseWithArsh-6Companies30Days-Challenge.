# Friends Of Appropriate Ages

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/friends-of-appropriate-ages/)

There are `n` persons on a social media website. You are given an integer array 
`ages` where `ages[i]` is the age of the ith person.

A Person `x` will not send a friend request to a person `y (x != y)` if any of the following conditions is true:
- `age[y] <= 0.5 * age[x] + 7`
- `age[y] > age[x]`
- `age[y] > 100 && age[x] < 100`

Otherwise, x will send a friend request to y.
Note that if `x` sends a request to `y`, `y` will not necessarily send a request to `x`. 
Also, a person will not send a friend request to themself.

Return the total number of friend requests made.

### Sample Input
```
 ages = [20,30,100,110,120]
```

### Sample Output
```
3

Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.
 
```

### Solution
```cpp
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int,int> mp;

        for(auto i: ages)
            mp[i]++;
        
        int ans = 0;
        for(int i = 1; i <= 121; i++){
            if(mp.find(i) == mp.end()) continue;

            int temp = 0;
            for(int j = 1; j <= 121; j++){
                if(mp.find(i) == mp.end()) continue;

                if(i == j && j > (i*0.5+7)){
                    temp += mp[i] - 1;
                }
                else if(!(j <= i*0.5 + 7) && !(j > i) && !(i < 100 && j > 100)){
                    temp += mp[j];
                }
            }  
            ans += mp[i] * temp;
        }
        return ans;
    }
};
```
