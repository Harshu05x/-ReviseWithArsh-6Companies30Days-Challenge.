# Count Subtrees With Max Distance Between Cities

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/description/)

There are n cities numbered from 1 to n. You are given an array edges of size n-1, 
where edges[i] = [ui, vi] represents a bidirectional edge between cities ui and vi. 
There exists a unique path between each pair of cities. In other words, the cities form a tree.

A subtree is a subset of cities where every city is reachable from every other city in the subset, 
where the path between each pair passes through only the cities from the subset. 
Two subtrees are different if there is a city in one subtree that is not present in the other.

For each d from 1 to n-1, find the number of subtrees in which the maximum distance between 
any two cities in the subtree is equal to d.

Return an array of size n-1 where the dth element (1-indexed) is the number of subtrees in 
which the maximum distance between any two cities is equal to d.

Notice that the distance between the two cities is the number of edges in the path between them.

### Sample Input
```
n = 4, edges = [[1,2],[2,3],[2,4]]
```

### Sample Output
```
[3,4,0]

Explanation:
The subtrees with subsets {1,2}, {2,3} and {2,4} have a max distance of 1.
The subtrees with subsets {1,2,3}, {1,2,4}, {2,3,4} and {1,2,3,4} have a max distance of 2.
No subtree has two nodes where the max distance between them is 3.

```

### Solution
```cpp
class Solution {
public:
    int dfs_cnt(int node,int mask,vector<vector<int>> &adj,vector<int> &vis){
        vis[node]=1;
        int cnt=1;
        for(int it:adj[node]){
            if(vis[it]==1) continue;
            if(mask & (1<<it)){
                cnt+=dfs_cnt(it,mask,adj,vis);
            }
        }
        return cnt;
    }
    int diameter(int node,int mask,vector<vector<int>> &adj,vector<int> &vis,int &dm){
        vis[node]=1;
        int l=0,r=0;
        for(int it:adj[node]){
            if(vis[it]==1) continue;
            if(mask & (1<<it)){
                int h=diameter(it,mask,adj,vis,dm);
                if(h>r){
                    l=r;
                    r=h;
                }else{
                    l=max(l,h);
                }
            }
        }
        dm=max(dm,l+r+1);
        return 1+max(l,r);
    }

    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans(n-1,0);
        for(int mask=0;mask<(1<<n);mask++){
            int cnt=__builtin_popcount(mask);
            vector<int> vis(n,-1);
            vector<int> vis1(n,-1);
            for(int i=0;i<n;i++){
                if(mask & (1<<i)){
                    if(dfs_cnt(i,mask,adj,vis)!=cnt) continue;
                    int dm=0;
                    int d=diameter(i,mask,adj,vis1,dm);
                    cout<<mask<<" "<<d<<"\n";
                    if(dm-2>=0) ans[dm-2]++;
                    break;
                }
            }
        }
        return ans;
    }
};
```
