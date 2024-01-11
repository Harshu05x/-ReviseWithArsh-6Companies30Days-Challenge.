# Top K Frequent Words

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/top-k-frequent-words/)

Given an array of strings `words` and an integer `k`, return the k most frequent strings.

Return the answer `sorted` by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

### Sample Input
```
 words = ["i","love","leetcode","i","love","coding"], k = 2
```

### Sample Output
```
["i","love"]

Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
```

### Solution
```cpp
class Solution {
public:
    static bool myCmp(pair<string,int>& a, pair<string,int>& b){
        if(a.second < b.second)
            return true;
        if(a.second == b.second)
            return a.first > b.first;
        return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        
        for(auto str: words)
            mp[str]++;
    
        vector<pair<string,int>> arr;
        for(auto i: mp){
            arr.push_back({i.first,i.second});
        }

        sort(arr.begin(),arr.end(),myCmp);

        int n = arr.size();
        vector<string> ans;
        for(int i = n-1; i >= n-k; i--)
            ans.push_back(arr[i].first);
        return ans;
    }
};
```
