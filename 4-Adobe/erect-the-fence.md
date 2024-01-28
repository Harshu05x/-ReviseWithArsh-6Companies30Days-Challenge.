# Erect the Fence

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/erect-the-fence/description/)

You are given an array trees where trees[i] = [xi, yi] represents the location of a tree in the garden.

Fence the entire garden using the minimum length of rope, as it is expensive. The garden is well-fenced only if all the trees are enclosed.

Return the coordinates of trees that are exactly located on the fence perimeter. You may return the answer in any order.

### Sample Input
```
trees = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
```
### Sample Output
```
[[1,1],[2,0],[4,2],[3,3],[2,4]]
Explanation: All the trees will be on the perimeter of the fence except the tree at [2, 2], 
which will be the fence.
```

### Solution
```cpp
class Solution {
public:
    int clockwise(vector<int>& p1, vector<int>& p2, vector<int>& p3) {
        int x1, y1, x2, y2, x3, y3;
        x1 = p1[0];
        y1 = p1[1];
        x2 = p2[0];
        y2 = p2[1];
        x3 = p3[0];
        y3 = p3[1];
        return ((y3-y2)*(x2-x1) - (y2-y1)*(x3-x2));
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end());
        vector<vector<int>> upper;
        vector<vector<int>> lower;
        for(auto tree:trees) {
            while(upper.size() > 1 and clockwise(upper[upper.size()-1], upper[upper.size()-2], tree) > 0) {
                upper.pop_back();
            }
            while(lower.size() > 1 and clockwise(lower[lower.size()-1], lower[lower.size()-2], tree) < 0) {
                lower.pop_back();
            }
            upper.push_back(tree);
            lower.push_back(tree);
        }
        vector<vector<int>> output;
        merge(upper.begin(), upper.end(), lower.begin(), lower.end(), back_inserter(output));
        auto pts = unique(output.begin(), output.end());
        output.erase(pts, output.end());
        return output;
    }
};
```
