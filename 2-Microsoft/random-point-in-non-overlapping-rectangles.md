# Random Point in Non-overlapping Rectangles


[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/)

You are given an array of non-overlapping axis-aligned rectangles `rects` where `rects[i] = [ai, bi, xi, yi]` 
indicates that `(ai, bi)` is the `bottom-left corner` point of the ith rectangle and `(xi, yi) is the top-right corner` 
point of the ith rectangle. Design an algorithm to `pick a random integer point` inside the space covered by one of the given rectangles.
A point on the perimeter of a rectangle is included in the space covered by the rectangle.

Any integer point inside the space covered by one of the given rectangles should be equally likely to be returned.

Note that an integer point is a point that has integer coordinates.

Implement the Solution class:

- `Solution(int[][] rects)` Initializes the object with the given rectangles `rects`.
- `int[] pick()` Returns a random integer point `[u, v]` inside the space covered by one of the given rectangles.

### Sample Input
```
["Solution", "pick", "pick", "pick", "pick", "pick"]
[[[[-2, -2, 1, 1], [2, 2, 4, 6]]], [], [], [], [], []]
```

### Sample Output
```
[null, [1, -2], [1, -1], [-1, -2], [-2, -2], [0, 0]]

Explanation
Solution solution = new Solution([[-2, -2, 1, 1], [2, 2, 4, 6]]);
solution.pick(); // return [1, -2]
solution.pick(); // return [1, -1]
solution.pick(); // return [-1, -2]
solution.pick(); // return [-2, -2]
solution.pick(); // return [0, 0]
```

### Solution
```cpp
class Solution {
    vector<vector<int>> arr;
    int i,x,y;
public:
    Solution(vector<vector<int>>& rects) {
        this->arr = rects;
        this->i = 0;
        this->x = arr[0][0];
        this->y = arr[0][1]; 
    }
    
    vector<int> pick() {
        auto ans = {x,y};
        
        x++;
        // if x exceeds then increment y and reset x
        if(x > arr[i][2]){
            x = arr[i][0];
            y++;
            // if y exceeds then increment i 
            // and take x & y to next rectangle
            if(y > arr[i][3]){
                i++;
                // if i exceeds then reset i
                if(i >= arr.size())
                    i = 0;
                x = arr[i][0];
                y = arr[i][1];
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
```
