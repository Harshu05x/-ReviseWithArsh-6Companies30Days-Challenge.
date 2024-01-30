# Number of Good Leaf Nodes Pairs

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/)

You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of 
a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.

Return the number of good leaf node pairs in the tree.

### Sample Input
```
root = [1,2,3,null,4], distance = 3
```

### Sample Output
```
1

Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.
```

### Solution
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int cnt = 0;
        finddegree(root, distance, cnt);
        return cnt;
    }

    vector<int> finddegree(TreeNode* root, int distance, int &cnt){
        vector<int> ret(10, 0);
        if(!root) return ret;
        if(!root->left && !root->right){
            ret[0] = 1;
            return ret;
        }
        vector<int> l, r;
        if(root->right){
            r = finddegree(root->right, distance, cnt);
            for(int i = 1; i < 10; i++){
                ret[i] += r[i - 1];
            }
        }
        if(root->left){
            l = finddegree(root->left, distance, cnt);
            for(int i = 1; i < 10; i++){
                ret[i] += l[i - 1];
            }
        }        
        if(root->left && root->right){
            for(int i = 0; i < 10; i++){
                int dis = distance - (i + 1);
                if(dis >= 1){
                    for(int j = 0; j < dis; j++){
                        cnt += (l[i] * r[j]);
                    }
                }
            }
        }
        return ret;
    }
};
```
