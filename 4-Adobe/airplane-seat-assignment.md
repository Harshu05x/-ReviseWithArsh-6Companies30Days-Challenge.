# Airplane Seat Assignment Probability

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/airplane-seat-assignment-probability/description/)

`n` passengers board an airplane with exactly `n` seats. The first passenger has lost the ticket 
and picks a seat randomly. But after that, the rest of the passengers will:
- Take their own seat if it is still available, and
- Pick other seats randomly when they find their seat occupied

Return the probability that the nth person gets his own seat.

### Sample Input
```
n = 1
```

### Sample Output
```
1.00000

Explanation: The first person can only get the first seat.
 
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
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n == 1)
            return 1.0000;
        return 0.50000;
    }
};
```
