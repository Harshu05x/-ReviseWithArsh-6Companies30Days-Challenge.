# Find Missing And Repeating

[![Problem Link](https://img.shields.io/badge/GeeksforGeeks-298D46?style=for-the-badge&logo=geeksforgeeks&logoColor=white)](https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1)

Given an `unsorted array` Arr of size N of positive integers. 
One number 'A' from set {1, 2,....,N} is `missing` and one number 'B' `occurs twice` in array. Find these two numbers.


### Sample Input
```
{1, 3, 3}
```
### Sample Output
```
3 2
Repeating number is 3 and 
smallest positive missing number is 2.
```

### Solution
```cpp
class Solution{
public:
    vector<int> findTwoElement(vector<int> nums, int n) {
        vector<int> hash(n+1,0);
        int repeating = -1;
        int missing = -1;
        
        for(auto i: nums)
            hash[i]++;
        
        for(int i = 1; i <= n; i++){
            if(hash[i] == 0)
                missing = i;
            else if(hash[i] == 2)
                repeating = i;
            
            if(missing != -1 && repeating != -1)
                return {repeating,missing};
            
        }
        
        return {-1,-1};
    }
};
```

