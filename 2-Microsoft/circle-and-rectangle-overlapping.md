# Circle and Rectangle Overlapping

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/circle-and-rectangle-overlapping/description/)

You are given a `circle` represented as `(radius, xCenter, yCenter)` and 
an axis-aligned `rectangle` represented as `(x1, y1, x2, y2)`,
where `(x1, y1)` are the coordinates of the `bottom-left corner`, 
and `(x2, y2)` are the coordinates of the `top-right corner` of the rectangle.

Return `true`if the circle and rectangle are `overlapped` otherwise return `false`. 
In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.

### Sample Input
```
radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
```
![image](https://github.com/Harshu05x/ReviseWithArsh-6Companies30Days-Challenge/assets/96901785/6cad5865-ec3c-4639-9a34-8c27dc3afe04)

### Sample Output
```
true

Explanation: Circle and rectangle share the point (1,0).
```

### Solution
```cpp
class Solution {
public:
    bool checkOverlap(int r, int cx, int cy, int x1, int y1, int x2, int y2) {
        for(int x = x1; x <= x2; x++){
            for(int y = y1; y <= y2; y++){
                // distance between the two points is sqrt of ((x2 – x1)² + (y2 – y1)²).
                int dist = pow((x-cx),2) + pow((y-cy),2);
                if(dist <= r*r)
                    return true;
            }
        }
        return false;
    }
};
```
