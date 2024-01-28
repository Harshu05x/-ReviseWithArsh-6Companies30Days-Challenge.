# Count the Number of Square-Free Subsets

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/count-the-number-of-square-free-subsets/description/)

You are given a positive integer `0-indexed array nums`.

A subset of the array nums is `square-free` if the product of its elements is a square-free integer.

A square-free integer is an integer that is divisible by no square number other than `1`.

Return the number of square-free non-empty subsets of the array nums. Since the answer may be too large, return it modulo `10*9 + 7`.

A non-empty subset of `nums` is an array that can be obtained by deleting some (possibly none but not all) elements from nums. 
Two subsets are different if and only if the chosen indices to delete are different.

### Sample Input
```
nums = [3,4,4,5]
```

### Sample Output
```
3

Explanation: There are 3 square-free subsets in this example:
- The subset consisting of the 0th element [3]. The product of its elements is 3, which is a square-free integer.
- The subset consisting of the 3rd element [5]. The product of its elements is 5, which is a square-free integer.
- The subset consisting of 0th and 3rd elements [3,5]. The product of its elements is 15, which is a square-free integer.
It can be proven that there are no more than 3 square-free subsets in the given array.
```

### Solution
```cpp
#define ll long long
#define md 1000000007
class Solution
{
public:
   int squareFreeSubsets(vector<int> &v)
   {
      ll n=v.size();
      ll a[10]={2,3,5,7,11,13,17,19,23,29};
      ll dp[n+1][1024];
      for(int i=0;i<1024;i++)
          dp[n][i]=1;
      for(ll i=n-1;i>=0;i--)
      {
          for(ll j=1023;j>=0;j--)
          {
              dp[i][j]=dp[i+1][j];
              bool ck=1;
              ll nj=j;
              ll ele=v[i];
              for(ll k=0;k<10;k++)
              {
                  while (ele%a[k]==0)
                  {
                      ele/=a[k];
                      if ((nj & 1<<k)>>k)
                      {
                          ck=0;
                          break;
                      }
                      else
                          nj=(nj | 1<<k);
                  }
              }
              if (ck)
              dp[i][j]=(dp[i][j]+dp[i+1][nj])%md;
          }
      }
      return (dp[0][0]-1+md)%md;
   }
};
```
