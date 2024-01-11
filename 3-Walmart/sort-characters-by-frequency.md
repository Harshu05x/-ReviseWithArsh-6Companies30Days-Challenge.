# Sort Characters By Frequency

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/sort-characters-by-frequency/description/)

Given a string `s`, `sort` it in `decreasing` order based on the `frequency` of the characters. 
The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

### Sample Input
```
s = "tree"
```

### Sample Output
```
"eert"

Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
```

### Solution
```cpp
class Solution {
public:
    void countFreq(string& s,priority_queue<pair<int,char>>& pq){
        // count freq of each elemnts and store in maxHeap
        // on the basis whose freq is max
        for(int i = 0; i < s.size(); i++){
            int curr = s[i];
            int j = i+1;
            int count = 1;
            // counting freq 
            while(j < s.size() && s[j] == curr){
                count++;
                j++;
            }
            // push count and ele
            pq.push({count,s[i]});
            // move i 
            i = j-1;
        }
    }
    
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        sort(s.begin(),s.end());

        string ans = "";   
        countFreq(s,pq);     
        while(!pq.empty()){
            auto top = pq.top();
            while(top.first--)
                ans += top.second;
            pq.pop();
        }
        return ans;
    }
};
```
