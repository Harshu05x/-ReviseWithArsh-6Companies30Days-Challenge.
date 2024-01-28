# Constrained Subsequence Sum

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/constrained-subsequence-sum/)

Given an integer array `nums` and an integer `k`, return the maximum sum of a non-empty 
subsequence of that array such that for every two consecutive integers in the subsequence, 
`nums[i] and nums[j]`, where `i < j`, the condition `j - i <= k` is satisfied.

A subsequence of an array is obtained by deleting some number of elements (can be zero) 
from the array, leaving the remaining elements in their original order.

### Sample Input
```
nums = [10,2,-10,5,20], k = 2
```

### Sample Output
```
37

Explanation: The subsequence is [10, 2, 5, 20]. 
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
