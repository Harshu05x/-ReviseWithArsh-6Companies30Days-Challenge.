# Kth Largest Element in a Stream

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/kth-largest-element-in-a-stream/)

Design a class to find the `kth largest element` in a stream. 
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Implement KthLargest class:
- `KthLargest(int k, int[] nums)` Initializes the object with the integer k and the stream of integers nums.
- `int add(int val)` Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
 

### Sample Input
```
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
```

### Sample Output
```
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
 
```
### Sample Input
```
n = 2
```

### Sample Output
```
0.50000

Explanation: he second person has a probability of 0.5 to get the second seat (when first person gets the first seat).
 
```

### Solution
```cpp
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int sz;
    KthLargest(int k, vector<int>& nums) {
        sz = k;
        for(auto i : nums){
            pq.push(i);
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > sz)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```
