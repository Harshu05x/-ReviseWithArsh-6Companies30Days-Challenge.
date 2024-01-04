# Number of People Aware of a Secret

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/)

On day `1`, one person discovers a secret.
You are given an integer `delay`, which means that each person will share the secret with a new person every day, 
starting from `delay days after` discovering the secret. You are also given an integer `forget`, which means that each person will forget 
the secret `forget days after` discovering it. A person cannot share the secret on the same day they forgot it, or on any day afterwards.
Given an integer `n`, return the number of people `who know the secret at the end of day n`. Since the answer may be very large, 
return it `modulo 10*9 + 7`.

### Sample Input
```
n = 6, delay = 2, forget = 4
```
### Sample Output
```
Output: 5

Explanation:
Day 1: Suppose the first person is named A. (1 person)
Day 2: A is the only person who knows the secret. (1 person)
Day 3: A shares the secret with a new person, B. (2 people)
Day 4: A shares the secret with a new person, C. (3 people)
Day 5: A forgets the secret, and B shares the secret with a new person, D. (3 people)
Day 6: B shares the secret with E, and C shares the secret with F. (5 people)
```

### Solution
```cpp

class Solution {
#define mod 1000000007
public:
    int recursive(int i,int& n, int& d, int& f, vector<int>& dp){
        if(i+d > n)
            return 1;

        if(dp[i] != -1)
            return dp[i];

        int sum = 1;
        for(int ind = i+d ; ind <= min(n,i+f); ind++){
            if(ind == i+f){
                sum--;
                break;
            }
            sum = (sum%mod + recursive(ind,n,d,f,dp)%mod)%mod;
        }
        return dp[i] = sum;
    }
    int peopleAwareOfSecret(int n, int d, int f) {
        vector<int> dp(n+1,-1);
        return recursive(1,n,d,f,dp);
    }
};

```
