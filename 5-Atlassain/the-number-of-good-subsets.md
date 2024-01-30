# The Number of Good Subsets

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/the-number-of-good-subsets/)

You are given an integer array nums. We call a subset of nums good if its product can be represented as a product of one or more distinct prime numbers.

For example, if nums = [1, 2, 3, 4]:
- [2, 3], [1, 2, 3], and [1, 3] are good subsets with products 6 = 2*3, 6 = 2*3, and 3 = 3 respectively.
- [1, 4] and [4] are not good subsets with products 4 = 2*2 and 4 = 2*2 respectively.

Return the number of different good subsets in nums modulo 10*9 + 7.

A subset of nums is any array that can be obtained by deleting some (possibly none or all) 
elements from nums. Two subsets are different if and only if the chosen indices to delete are different.

### Sample Input
```
nums = [1,2,3,4]
```

### Sample Output
```
6

Explanation: The good subsets are:
- [1,2]: product is 2, which is the product of distinct prime 2.
- [1,2,3]: product is 6, which is the product of distinct primes 2 and 3.
- [1,3]: product is 3, which is the product of distinct prime 3.
- [2]: product is 2, which is the product of distinct prime 2.
- [2,3]: product is 6, which is the product of distinct primes 2 and 3.
- [3]: product is 3, which is the product of distinct prime 3.
 
```

### Solution
```cpp
class Solution {
public:
    long mod = 1e9 + 7;
    vector<int> demo;
    unordered_map<int,int> mp;
    unordered_map<int,int> freq;
    long long power(long long x, unsigned int y, int p)
    {
        long long res = 1;  
        x = x % p; 
        if (x == 0) return 0; 
        while (y > 0)
        {
            if (y & 1)
                res = (res*x) % p;
            y = y>>1;
            x = (x*x) % p;
        }
        return res;
    }

    int solve(int idx, int bitmask){
        if(idx == demo.size()){
            if(bitmask > 0) return 1;
            return 0;
        }
        
        long  not_take = solve(idx+1, bitmask);
        long  take = 0;
        if((demo[idx]&bitmask) == 0) take = (long)solve(idx+1, 
            bitmask|demo[idx])*(long)freq[demo[idx]];
        
        return (take + not_take)%mod;
    }

    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        
        int n = primes.size();
        for(auto i:nums) mp[i]++;
        int ones = 0;
        for(auto i:mp){
            int x = i.first;
            int y = i.second;
            int mask = 0;
            if(x == 1) ones = y;
            else {
                for(int j = 0; j<n; j++){
                    if(x%primes[j] == 0){
                        x = x/primes[j];
                        mask = mask|(1<<j);
                    }
                    if(x%primes[j] == 0 || x == 1) break;
                }
                if(x == 1){
                    demo.push_back(mask);
                    freq[mask] = y;
                }
            }
        }
        return power(2, ones, mod)%mod*solve(0, 0)%mod;
    }
};
```
