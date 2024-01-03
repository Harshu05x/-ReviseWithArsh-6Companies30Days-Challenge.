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
    string printMinNumberForPattern(string S){
        // code here 
        int n = S.length(); int i = 0; int current = 1;
        string ans;
        ans.push_back('1');
        while(i < n){
            if(S[i] == 'D'){
                int j = i;
                while(j < n && S[j] == 'D')
                    j++;
                    
                current += j-i;
                ans[i] = (current + '0');
                int c = current;
                while(i != j){
                    c--;
                    ans.push_back(c + '0');
                    i++;
                }
            }
            else{
                current++;
                ans.push_back(current + '0');
                i++;
            }
        }
        return ans;
    }
};
```

