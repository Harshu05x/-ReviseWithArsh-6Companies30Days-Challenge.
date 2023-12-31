# Letter Combinations of a Phone Number

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

Given a string containing digits from 2-9 inclusive, 
return `all possible letter combinations` that the number could represent. 
Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


### Sample Input
```
digits = "23"
```
### Sample Output
```
 ["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

### Solution
```cpp

class Solution {
public:
    unordered_map <int,string> mp = {   {2,"abc"}, {3,"def"}, {4,"ghi"},
                                        {5,"jkl"}, {6,"mno"}, {7,"pqrs"},
                                        {8,"tuv"}, {9,"wxyz"}
                                    };

    void solve(string& digits, int i, vector<string>& ans, string& output){
        if(i >= digits.size()){
            ans.push_back(output);
            return ;
        }

        int index = digits[i] - '0';
        
        for(int x = 0; x < mp[index].size(); x++){
            output.push_back(mp[index][x]);
            solve(digits,i+1,ans,output);
            output.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0)
            return ans;
        int i = 0;
        string output = "";
        solve(digits,i,ans,output);
        if(ans.size() == 0) ans.pop_back();
        return ans;
    }
};
```
