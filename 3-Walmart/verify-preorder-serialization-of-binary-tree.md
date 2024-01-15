# Verify Preorder Serialization of a Binary Tree

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/)

One way to serialize a binary tree is to use `preorder traversal`. When we encounter a non-null node, 
we record the node's value. If it is a null node, we record using a sentinel value such as `'#'`.

![image](https://github.com/Harshu05x/ReviseWithArsh-6Companies30Days-Challenge/assets/96901785/9f412e92-feca-4780-b831-6dee5fd3af8d)

For example, the above binary tree can be serialized to the string `"9,3,4,#,#,1,#,#,2,#,6,#,#"`, where '#' represents a null node.
Given a string of comma-separated values `preorder`, return `true` if it is a correct preorder traversal serialization of a binary tree.
It is guaranteed that each comma-separated value in the string must be either an integer or a character '#' representing null pointer.
You may assume that the input format is always `valid`.
For example, it could never contain two consecutive commas, such as "1,,3".
Note: You are not allowed to reconstruct the tree.

### Sample Input
```
preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
```

### Sample Output
```
true
```
### Sample Input
```
preorder = "9,#,#,1"
```

### Sample Output
```
false
```

### Solution
```cpp
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int temp = 1;

        for(int i = 0; i < preorder.size(); i++){
            if(preorder[i] == ',')
                continue;
            temp--;
            while(i < preorder.size() && preorder[i] != '#' && preorder[i] != ',') 
                i++;
            if(temp < 0)
                return false;
            if(preorder[i] != '#')
                temp += 2;
        }
        if(temp) return false;
        return true;
    }
};
```
