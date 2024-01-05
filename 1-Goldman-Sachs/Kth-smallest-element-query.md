# Query Kth Smallest Trimmed Number

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/query-kth-smallest-trimmed-number/description/)

You are given a 0-indexed array of strings `nums`, where `each string is of equal length` and consists of only digits.

You are also given a 0-indexed 2D integer array `queries` where `queries[i] = [ki, trimi]`. For each `queries[i]`, you need to:
- Trim each number in nums to its `rightmost trimi` digits.
- Determine the index of the `kth smallest trimmed number` in nums.
  If two trimmed numbers are equal, the number with the lower index is considered to be smaller.
- Reset each number in `nums` to its original length.

Return an `array answer` of the `same length as queries`, where `answer[i]`is the answer to the `ith query`.

Note:
- To trim to the rightmost x digits means to keep removing the leftmost digit, until only x digits remain.
- Strings in nums may contain leading zeros.
 
### Sample Input
```
nums = ["102","473","251","814"], queries = [[1,1],[2,3],[4,2],[1,2]]
```
### Sample Output
```
[2,2,1,0]

Explanation:
1. After trimming to the last digit, nums = ["2","3","1","4"]. The smallest number is 1 at index 2.
2. Trimmed to the last 3 digits, nums is unchanged. The 2nd smallest number is 251 at index 2.
3. Trimmed to the last 2 digits, nums = ["02","73","51","14"]. The 4th smallest number is 73.
4. Trimmed to the last 2 digits, the smallest number is 2 at index 0.
   Note that the trimmed number "02" is evaluated as 2.
```

### Solution
```cpp
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        vector<int> ans;
        for(auto i: q){
            int k = i[0];
            int t = i[1];

            vector<pair<string,int>> temp;
            for(int j = 0; j < n; j++){
                string str;
                int k = nums[j].size()-t;
                for(; k < nums[j].size(); k++)
                    str += nums[j][k];
                temp.push_back({str,j});
            }
            sort(temp.begin(),temp.end());
            int idx = temp[k-1].second;
            ans.push_back(idx);
        }
        return ans;
    }
};
```
