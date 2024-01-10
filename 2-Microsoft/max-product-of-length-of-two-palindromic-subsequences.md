# Maximum Product of the Length of Two Palindromic Subsequences

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/description/)

Given a string s, find `two disjoint palindromic subsequences` of s such that the `product` of their `lengths` is `maximized`. 
The two subsequences are disjoint if they do not both pick a character at the same index.

Return the maximum possible product of the lengths of the two palindromic subsequences.

A subsequence is a string that can be derived from another string by deleting some or no characters without 
changing the order of the remaining characters. A string is palindromic if it reads the same forward and backward.

### Sample Input
```
 s = "leetcodecom"
```

### Sample Output
```
 9

Explanation: An optimal solution is to choose "ete" for the 1st subsequence and "cdc" for the 2nd subsequence.
The product of their lengths is: 3 * 3 = 9.
```

### Solution
```cpp
class Solution {
    vector<vector<int>>arr;
     bool isDisjoint(vector<int>& arr1, vector<int>& arr2){       
        for(auto i: arr1){
            for(auto j: arr2){
                if(i == j)
                    return false;
            }
        }
        return true;
    }

    bool isPalindrome(string& s, vector<int>& temp){
        int i = 0, j = temp.size()-1;

        while(i < j){
            if(s[temp[i]] != s[temp[j]])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void generateAllPalindrome(string& s, vector<int>& temp, int i){
        if(isPalindrome(s,temp)){
            arr.push_back(temp);
        }
        if(i >= s.size())
            return;
        
        // include
        temp.push_back(i);
        generateAllPalindrome(s,temp,i+1);
        // backtrack
        temp.pop_back();

        // exclude
        generateAllPalindrome(s,temp,i+1);
    }
public:
    int maxProduct(string s) {
        vector<int> temp;
        generateAllPalindrome(s,temp,0);

        int ans = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(isDisjoint(arr[i],arr[j])){
                    int temp = arr[i].size()*arr[j].size();
                    ans = max(temp,ans);
                }
            }
        }
        return ans;
    }
};
```
