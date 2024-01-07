# Shopping Offers

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/shopping-offers/description/)

In LeetCode Store, there are `n` items to sell. Each item has a price. However, there are some special offers, 
and a special offer consists of one or more different kinds of items with a sale price.

You are given an integer array `price` where `price[i]` is the `price` of the `ith item`, 
and an integer array `needs` where `needs[i]` is the number of pieces of the `ith` item you want to buy.

You are also given an array `special` where `special[i]` is of size `n + 1` where `special[i][j]` is the number of 
pieces of the `jth` item in the `ith` offer and `special[i][n]` (i.e., the last integer in the array) is the `price of the ith offer`.

Return the `lowest price` you have to pay for exactly certain items as given, where you could make optimal use of the special offers. 
You are not allowed to buy more items than you want, even if that would lower the overall price. 
You could use any of the special offers as many times as you want.

### Sample Input
```
price = [2,5], special = [[3,0,5],[1,2,10]], needs = [3,2]
```

### Sample Output
```
14

Explanation:
There are two kinds of items, A and B. Their prices are $2 and $5 respectively. 
In special offer 1, you can pay $5 for 3A and 0B
In special offer 2, you can pay $10 for 1A and 2B. 
You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.
```

### Solution
```cpp
class Solution {
public:
    int recursive(vector<int>& price, vector<vector<int>>& special, vector<int> needs, 
                int ind, int& n, int& m, map<int,map<vector<int>,int>>& dp){
        // Base case                               
        if(ind >= n){
            int ans = 0;
            for(int i = 0; i < m; i++)
                ans += needs[i]*price[i];
            return ans;
        }
        // check ans already exists in dp or not
        if(dp.find(ind) != dp.end() && dp[ind].find(needs) != dp[ind].end())
            return dp[ind][needs];

        int include = INT_MAX, exclude = INT_MAX;

        // check if we can include current offer or not
        // true - can include , false - can't include
        bool flag = true;           
        for(int i = 0; i < m; i++){
            if(special[ind][i] > needs[i]){
                flag = false;
                break;
            }
        }

        if(flag){
            // if we can include current offer then include it and update the needs
            for(int i = 0; i < m; i++){
                needs[i] -= special[ind][i];
            }
            // Include call with adding current offer price
            include = special[ind][m] + recursive(price,special,needs,ind,n,m,dp);
            // Backtrack and reset the needs array 
            for(int i = 0; i < m; i++){
                needs[i] += special[ind][i];
            }
        }
        // exclude call
        exclude = recursive(price,special,needs,ind+1,n,m,dp);

        // store minimum of both inlcude and exclude in dp and return ans 
        return  dp[ind][needs] = min(include,exclude);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = special.size();
        int m = price.size();
        map<int,map<vector<int>,int>> dp;
        return recursive(price,special,needs,0,n,m,dp);
    }
};
```
