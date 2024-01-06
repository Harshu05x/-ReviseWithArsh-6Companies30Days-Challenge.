# Russian Doll Envelopes

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/russian-doll-envelopes/description/)

You are given a 2D array of integers envelopes where `envelopes[i] = [wi, hi]` 
represents the `width` and the `height` of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope 
are greater than the other envelope's width and height.
Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

### Sample Input
```
envelopes = [[5,4],[6,4],[6,7],[2,3]]
```
### Sample Output
```
 3

Explanation:
The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
```

### Solution
```cpp
class Solution {
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),comp);
        int n = arr.size();
        vector<int> temp;
        temp.push_back(arr[0][1]);
        
        for(int index = 1; index < n; index++){
            if(temp.back() < arr[index][1]){
                temp.push_back(arr[index][1]);
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),arr[index][1]) - temp.begin();
                temp[ind] = arr[index][1];
            }
        }
    
        return temp.size();
    }
};
```
