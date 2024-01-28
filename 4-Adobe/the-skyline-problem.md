# The Skyline Problem

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/the-skyline-problem/description/)

A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from
a distance. Given the locations and heights of all the buildings, return the skyline formed by these buildings 
collectively.

The geometric information of each `building` is given in the array buildings where 
`buildings[i] = [lefti, righti, heighti]`:
- `lefti` is the x coordinate of the left edge of the ith building.
- `righti` is the x coordinate of the right edge of the ith building.
- `heighti` is the height of the ith building.

You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height `0`.

The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form 
`[[x1,y1],[x2,y2],...]`. Each key point is the left endpoint of some horizontal segment in the skyline except the 
last point in the list, which always has a y-coordinate `0` and is used to mark the skyline's termination where the 
rightmost building ends. Any ground between the leftmost and rightmost buildings should be part of the skyline's
contour.

Note: There must be no consecutive horizontal lines of equal height in the output skyline. For instance, 
`[...,[2 3],[4 5],[7 5],[11 5],[12 7],...]` is not acceptable; the three lines of height 5 should be merged into one
in the final output as such: `[...,[2 3],[4 5],[12 7],...]`

### Sample Input
```
buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
```
### Sample Output
```
[[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]

Explanation:
Figure A shows the buildings of the input.
Figure B shows the skyline formed by those buildings. The red points in figure B represent the key points in the output list. 
```

### Solution
```cpp
class Solution {
public:
    void make_xarr(vector<int> &xarr, vector<vector<int>> &buildings){
        for(auto b: buildings){
            xarr.push_back(b[0]);
            xarr.push_back(b[1]);
        }
        unique(begin(xarr),end(xarr));
    sort(begin(xarr),end(xarr));
    }

    int get_max(priority_queue<pair<int,int>> &pq, int x){
        int maxh=0;
        while(!pq.empty()){
            auto top=pq.top();
            if(top.second<=x) pq.pop();
            else{
                maxh=top.first;
                break;
            }
        }
    return maxh;
    }
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n=buildings.size();
        vector<vector<int>> result;
        vector<int> xarr(2*n);

        make_xarr(xarr, buildings);
        
        priority_queue<pair<int,int>> pq;
        int prevh=0, i=0;
        for(auto it : xarr){
            while(i<n and buildings[i][0]==it){
                pq.push(pair(buildings[i][2], buildings[i][1]));
                i++;
            }
            int maxh=get_max(pq,it);
            if(prevh!=maxh) result.push_back(vector<int> {(int)it, maxh});
            prevh=maxh;
        }
    return result;
    }
};
```
