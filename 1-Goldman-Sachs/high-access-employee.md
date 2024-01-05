# High-Access Employees  

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/high-access-employees/description/)

You are given a 2D 0-indexed array of strings, `access_times`, with size `n`. 
For each `i` where `0 <= i <= n - 1, access_times[i][0]` represents the `name` of an employee, 
and `access_times[i][1]` represents the access time of that employee. All entries in access_times are within the same day.

The access time is represented as `four digits using a 24-hour time format`, for example, "0800" or "2250".

An employee is said to be high-access if he has `accessed the system three or more times within a one-hour period`.

Times with exactly one hour of difference are not considered part of the same one-hour period. 
For example, `"0815" and "0915" are not part` of the same one-hour period.

Access times at the start and end of the day are not counted within the same one-hour period. 
For example, `"0005" and "2350" are not part` of the same one-hour period.

Return a list that contains the names of `high-access employees` with any order you want.

### Sample Input
```
 access_times = [["d","0002"],["c","0808"],["c","0829"],["e","0215"],["d","1508"],["d","1444"],["d","1410"],["c","0809"]]
```
### Sample Output
```
 ["c","d"]

Explanation:
"c" has three access times in the one-hour period of [08:08, 09:07] which are 08:08, 08:09, and 08:29.
"d" has also three access times in the one-hour period of [14:10, 15:09] which are 14:10, 14:44, and 15:08.
However, "e" has just one access time, so it can not be in the answer and the final answer is ["c","d"].
```

### Solution
```cpp
class Solution {
    int stringToNum(string str){
        int num = 0; 
        for (int i = 0; str[i] != '\0'; i++) { 
            num = num * 10 + (str[i] - 48); 
        } 
        return num;
    }
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& at) {
        unordered_map<string,vector<int>> mp;

        for(auto i: at){
            int num = stringToNum(i[1]);
            mp[i[0]].push_back(num);
        }

        vector<string> ans;
        for(auto str: mp){
            if(str.second.size() >= 3){
                int cnt = 1;
                sort(str.second.begin(),str.second.end());
                for(int i = 0; i < str.second.size()-1; i++){
                    int cnt = 1;
                    bool flag = false;
                    for(int j = i+1; j < str.second.size(); j++){
                        int diff = str.second[j] - str.second[i] - 40;
                        if(diff < 60)
                            cnt++;
                        if(cnt >= 3){
                            flag = true;
                            break;
                        }
                    }
                    if(flag){
                        ans.push_back(str.first);
                        break;
                    }
                }
            }
        }
        return ans;
    }
    

};
```
