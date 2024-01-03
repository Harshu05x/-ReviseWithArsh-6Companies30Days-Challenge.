# Number following a pattern

[![Problem Link](https://img.shields.io/badge/GeeksforGeeks-298D46?style=for-the-badge&logo=geeksforgeeks&logoColor=white)](https://www.geeksforgeeks.org/problems/number-following-a-pattern3126/1)

Given a pattern containing only I's and D's. 
I for `increasing` and D for `decreasing`. 
Devise an algorithm to print the minimum number following that pattern. 
Digits from `1-9` and digits can't repeat.


### Sample Input
```
IIDDD
```
### Sample Output
```
126543

Explanation:
1 < 2 < 6 > 5 > 4 > 3
  I - I - D - D - D
```

### Solution
```cpp
class Solution{   
public:
    string printMinNumberForPattern(string S){
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

