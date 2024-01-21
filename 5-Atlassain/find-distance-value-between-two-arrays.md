# Find the Distance Value Between Two Arrays

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/find-the-distance-value-between-two-arrays/description/)

Given two integer arrays `arr1` and `arr2`, and the integer `d`, 
return the distance value between the two arrays.

The distance value is defined as the number of elements `arr1[i]` such 
that there is not any element `arr2[j]` where `|arr1[i]-arr2[j]| <= d.`

### Sample Input
```
arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
```

### Sample Output
```
2

Explanation: 
For arr1[0]=4 we have: 
|4-10|=6 > d=2 
|4-9|=5 > d=2 
|4-1|=3 > d=2 
|4-8|=4 > d=2

For arr1[1]=5 we have: 
|5-10|=5 > d=2 
|5-9|=4 > d=2 
|5-1|=4 > d=2 
|5-8|=3 > d=2

For arr1[2]=8 we have:
|8-10|=2 <= d=2
|8-9|=1 <= d=2
|8-1|=7 > d=2
|8-8|=0 <= d=2
 
```

### Solution
```cpp
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;

        for(auto i: arr1){
            bool flag = true;
            for(auto j: arr2){
                int diff = abs(i-j);
                if(diff <= d){
                    flag = false;
                    break;
                }
            }
            if(flag)
                cnt++;
        }

        return cnt;
    }
};
```
