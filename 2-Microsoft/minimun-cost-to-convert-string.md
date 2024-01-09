# Minimum Cost to Convert String I

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/)

You are given two 0-indexed strings `source` and `target`, both of length `n` and consisting of `lowercase` English letters. 
You are also given two 0-indexed character arrays `original` and `changed`, and an integer array cost, where `cost[i]` 
represents the `cost` of changing the character `original[i]` to the character `changed[i]`.

You start with the string `source`. In one operation, you can pick a character `x` from the string and change it to 
the character `y` at a cost of `z` if there exists any index `j` such that `cost[j] == z`, `original[j] == x`, and `changed[j] == y`.

Return the `minimum cost` to convert the string `source` to the string `target` using any number of operations. 
If it is impossible to convert source to target, return `-1`.

Note that there may exist indices `i`, `j` such that `original[j] == original[i] and changed[j] == changed[i]`.

### Sample Input
```
source = "abcd", target = "acbe",
original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"],
cost = [2,5,5,1,2,20]
```

### Sample Output
```
28
Explanation:
To convert the string "abcd" to string "acbe":
- Change value at index 1 from 'b' to 'c' at a cost of 5.
- Change value at index 2 from 'c' to 'e' at a cost of 1.
- Change value at index 2 from 'e' to 'b' at a cost of 2.
- Change value at index 3 from 'd' to 'e' at a cost of 20.
The total cost incurred is 5 + 1 + 2 + 20 = 28.
It can be shown that this is the minimum possible cost.
```

### Solution
```cpp
 void floydWarshall(vector<vector<int>>& arr){
      for(int helper = 0; helper < 26; helper++){
          for(int i = 0; i < 26; i++){
              for(int j = 0; j < 26; j++)
                  arr[i][j] = min(arr[i][j], arr[i][helper]+arr[helper][j]);
          }
      }
  }
  long long minimumCost(string src, string des, vector<char>& original,
                        vector<char>& changed, vector<int>& cost) {
     int n = src.size();
      vector<vector<int>> arr(26,vector<int>(26,1e9));
      for(int i = 0; i < original.size(); i++){
          int x = original[i]-'a';
          int y = changed[i]-'a';
          arr[x][y] = min(arr[x][y],cost[i]);
      }

      floydWarshall(arr);

      long long ans = 0;
      for(int i = 0; i < n; i++){
          int x = src[i]-'a';
          int y = des[i]-'a';

          if(x == y)
              continue;
          else if(arr[x][y] == 1e9) 
              return -1;
          
          ans += arr[x][y];
      }    
      return ans;
      
  }
```
