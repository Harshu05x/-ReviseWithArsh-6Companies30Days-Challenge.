# Minimum Non-Zero Product of the Array Elements

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/description/)

You are given a positive integer p. Consider an array nums (1-indexed) that consists of the integers in the 
inclusive range [1, 2p - 1] in their binary representations. 
You are allowed to do the following operation any number of times:
- Choose two elements x and y from nums.
- Choose a bit in x and swap it with its corresponding bit in y. Corresponding bit refers to the bit that is in 
 the same position in the other integer.

For example, if x = 1101 and y = 0011, after swapping the 2nd bit from the right, we have x = 1111 and y = 0001.

Find the minimum non-zero product of nums after performing the above operation any number of times. Return this product modulo 109 + 7.

Note: The answer should be the minimum product before the modulo operation is done.

### Sample Input
```
p = 1
```

### Sample Output
```
1

Explanation: nums = [1].
There is only one element, so the product equals that element.
 
```

### Solution
```cpp
class Solution {
public:
    int minNonZeroProduct(int p) {
        long long ans = ((long long)(1)<<p) -1;
        int base = (1000000000+7);
        long long cur = ans  -1; 
        cur  = cur%base;
        ans = ans % base;

        int k = 0;
        while(k<=p-2){
            ans *= cur;
            cur *= cur;

            ans %= base;
            cur %=base;
            k++;
        } 
        return ans;
    }
};
```
