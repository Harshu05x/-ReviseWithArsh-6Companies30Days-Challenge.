# Trim a Binary Search Tree

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/trim-a-binary-search-tree/description/)

Given the `root` of a binary search tree and the lowest and highest boundaries as `low` and `high`, 
trim the tree so that all its elements lies in `[low, high]`. Trimming the tree should not change the relative 
structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant).
It can be proven that there is a unique answer.

Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.

### Sample Input
```
root = [3,0,4,null,2,null,null,1], low = 1, high = 3
```
![image](https://github.com/Harshu05x/ReviseWithArsh-6Companies30Days-Challenge/assets/96901785/173e9709-682d-453f-b0da-cfbb2809f407)

### Sample Output
```
[3,2,null,1]
 
```

### Solution
```cpp
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) { 
            return root;
        }
        
        if (root->val >= low && root->val <= high) { 
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;
        }
        
        if (root->val < low) {
            return trimBST(root->right, low, high);
        }
            
        return trimBST(root->left, low, high);
    }
};
```
