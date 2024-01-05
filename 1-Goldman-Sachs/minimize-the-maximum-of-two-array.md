# Minimize the Maximum of Two Arrays

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/)

We have two arrays `arr1` and `arr2` which are initially empty. You need to add positive integers to them such that 
they satisfy all the following conditions:
- `arr1` contains `uniqueCnt1 distinct` positive integers, each of which is `not divisible by divisor1`.
- `arr2` contains `uniqueCnt2 distinct` positive integers, each of which is `not divisible by divisor2`.
- No integer is present in both arr1 and arr2.

Given `divisor1, divisor2, uniqueCnt1, and uniqueCnt2`, return the `minimum possible maximum integer` that can be present in either array.

### Sample Input
```
divisor1 = 2, divisor2 = 4, uniqueCnt1 = 8, uniqueCnt2 = 2
```
### Sample Output
```
15

Explanation: 
Here, the final possible arrays can be arr1 = [1,3,5,7,9,11,13,15], and arr2 = [2,6].
It can be shown that it is not possible to obtain a lower maximum satisfying all conditions. 
```

### Solution
```cpp

```
