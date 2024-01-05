# Find Consecutive Integers from a Data Stream
  
[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/description/)

For a stream of integers, implement a data structure that checks if the last `k` integers parsed in the stream are equal to `value`.

Implement the DataStream class:
- `DataStream(int value, int k)` Initializes the object with an empty integer stream and the two integers `value` and `k`.
- `boolean consec(int num)` Adds `num` to the stream of integers. Returns `true` if the last `k` integers are equal to value,
and `false` otherwise. If there are less than k integers, the condition does not hold true, so returns `false`.

### Sample Input
```
["DataStream", "consec", "consec", "consec", "consec"]
[[4, 3], [4], [4], [4], [3]]
```
### Sample Output
```
[null, false, false, true, false]

Explanation
DataStream dataStream = new DataStream(4, 3); //value = 4, k = 3 
dataStream.consec(4); // Only 1 integer is parsed, so returns False. 
dataStream.consec(4); // Only 2 integers are parsed.
                      // Since 2 is less than k, returns False. 
dataStream.consec(4); // The 3 integers parsed are all equal to value, so returns True. 
dataStream.consec(3); // The last k integers parsed in the stream are [4,4,3].
                      // Since 3 is not equal to value, it returns False.
```

### Solution
```cpp

class DataStream {
    map<int,int> mp;
    queue<int> que;
    int val, k;
public:
    DataStream(int value, int k) {
        this->val = value;
        this->k = k;
    }
    
    bool consec(int num) {
        mp[num]++;
        que.push(num);
        bool ans = (num == val && que.size() == k && mp.size() == 1);
        
        if(que.size() == k){
            int front = que.front();
            que.pop();
            mp[front]--;
            if(mp[front] == 0)
                mp.erase(front);
        }
        return ans;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
```
