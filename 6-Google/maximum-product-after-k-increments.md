#  Maximum Product After K Increments

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/maximum-product-after-k-increments/description/)

You are given an array of non-negative integers nums and an integer k. In one operation, 
you may choose any element from nums and increment it by 1.

Return the maximum product of nums after at most k operations. Since the answer may be very large, 
return it modulo 10*9 + 7. Note that you should maximize the product before taking the modulo. 

### Sample Input
```
nums = [0,4], k = 5
```

### Sample Output
```
20

Explanation: Increment the first number 5 times.
Now nums = [5, 4], with a product of 5 * 4 = 20.
It can be shown that 20 is maximum product possible, so we return 20.
Note that there may be other ways to increment nums to have the maximum product.
```

### Solution
```cpp
class Solution {
    int mod=(int)(1e9+7);
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>q(nums.begin(),nums.end());
        
        while(k>0){
            int num=q.top();
            num=num+1;
            q.pop();
            q.push(num);
            k--;
        }
        long long int sum=1;
        while(!q.empty()){
            sum=(sum*q.top())%mod;
            q.pop();
        }
        return sum%mod;
    }
};
```
