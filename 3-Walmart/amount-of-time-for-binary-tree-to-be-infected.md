# Amount of Time for Binary Tree to Be Infected

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/)

You are given the root of a `binary tree` with unique values, and an integer start. 
At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:
- The node is currently uninfected.
- The node is adjacent to an infected node.

Return the number of minutes needed for the entire tree to be infected.


### Sample Input
```
root = [1,5,3,null,4,10,6,9,2], start = 3
```
![image](https://github.com/Harshu05x/ReviseWithArsh-6Companies30Days-Challenge/assets/96901785/e7792d91-428a-4c9d-9e34-1ffcded5e390)

### Sample Output
```
4

Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.
```

### Solution 
```cpp
class Solution {
    unordered_map<int, unordered_set<int>> adjList;
    void convertToGraph(TreeNode* current, int parent) {
        if (current == nullptr) {
            return;
        } 
        if (adjList.find(current->val) == adjList.end()) {
            adjList[current->val] = unordered_set<int>();
        }
        unordered_set<int>& adjacentList = adjList[current->val];
        if (parent != 0) {
            adjacentList.insert(parent);
        } 
        if (current->left != nullptr) {
            adjacentList.insert(current->left->val);
        } 
        if (current->right != nullptr) {
            adjacentList.insert(current->right->val);
        }
        convertToGraph(current->left, current->val);
        convertToGraph(current->right, current->val);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        convertToGraph(root,0);

        // BFS on graph
        unordered_map<int,bool> vis;
        queue<pair<int,int>> que;

        que.push({start,0});
        vis[start] = true;
        int time = 0;
        
        while(!que.empty()){
            auto front = que.front();
            que.pop();
            int node = front.first;
            int lvl = front.second;
            time = max(time,lvl);

            for(auto nbr: adjList[node]){
                if(!vis[nbr]){
                    vis[nbr] = true;
                    que.push({nbr,lvl+1});
                }
            }
        }
        return time;
    }
};
```
