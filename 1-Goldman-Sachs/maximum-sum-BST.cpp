// Leetcode 1373. Maximum Sum BST in Binary Tree

// Given a binary tree root, return the maximum sum of all keys of 
// any sub-tree which is also a Binary Search Tree (BST).

// Assume a BST is defined as follows:
// --> The left subtree of a node contains only nodes with keys less than the node's key.
// --> The right subtree of a node contains only nodes with keys greater than the node's key.
// --> Both the left and right subtrees must also be binary search trees.

// Example 1.
//     Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
//     Output: 20
//     Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.

// Example 2.
//     Input: root = [4,3,null,1,2]
//     Output: 2
//     Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.



class Solution {
public:
    // pair<pair<bool,int>,pair<int,int>> 
    // {{validBST,sum},{max,min}}
    pair<pair<bool,int>,pair<int,int>> helper(TreeNode* root, int& ans){
        // base case--> root == null then return 
        //          1] BST is valid, 2] as it is null so sum is zero
        //          3] max val is INT_MIN & 4] min val is INT_MAX becoz BST not exists right now
        if(root == NULL)
            return {{true,0},{INT_MIN,INT_MAX}};
        
        // find left and right ans
        pair<pair<bool,int>,pair<int,int>> leftAns = helper(root->left,ans);
        pair<pair<bool,int>,pair<int,int>> rightAns = helper(root->right,ans);

        // bulid curr ans 
        pair<pair<bool,int>,pair<int,int>> currAns;
        // find out sum
        int sum = root->val + leftAns.first.second + rightAns.first.second;
        currAns.first.second = sum;
        currAns.second.first = max(root->val,rightAns.second.first);    // max val in curr BST
        currAns.second.second = min(root->val,leftAns.second.second);   // min val in curr BST

        // if left && right is valid && (left.max < root.val < right.min) 
        // then curr BST is also valid
        if(leftAns.first.first && rightAns.first.first &&
            (root->val > leftAns.second.first && root->val < rightAns.second.second))
                currAns.first.first = true;
        
        // if curr BST is valid then only update ans
        if(currAns.first.first) ans = max(ans,currAns.first.second);

        return currAns;
    }
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        helper(root,ans);
        return ans;
    }
};
