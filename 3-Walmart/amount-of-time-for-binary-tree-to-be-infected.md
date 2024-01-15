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
