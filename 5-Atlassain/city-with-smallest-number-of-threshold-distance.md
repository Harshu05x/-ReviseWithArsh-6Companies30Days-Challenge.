# Find the City With the Smallest Number of Neighbors at a Threshold Distance

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/)

There are `n` cities numbered from `0 to n-1`. Given the array edges where `edges[i] = [fromi, toi, weighti]` 
represents a `bidirectional and weighted edge`between cities fromi and toi, and given the integer `distanceThreshold`.

Return the city with the smallest number of cities that are reachable through some path and whose distance 
is `at most distanceThreshold`, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

### Sample Input
```
n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
```
![image](https://github.com/Harshu05x/ReviseWithArsh-6Companies30Days-Challenge/assets/96901785/62ee7d26-7645-4d87-bc3e-56dd5a041818)

### Sample Output
```
3

The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
```

### Solution 1 - using Dijkstra algorithm
```cpp
class Solution {
    void makeAdjList(unordered_map<int,list<pair<int,int>>>& adjList, 
                    vector<vector<int>>& edges){
    
        for(auto i: edges){
            adjList[i[0]].push_back({i[1],i[2]});
            adjList[i[1]].push_back({i[0],i[2]});
        }
    }
    vector<int> shorestDis(int src,int n, int dt, 
        unordered_map<int,list<pair<int,int>>>& adjList){
        // create set and dist vector
        set<pair<int,int>> st;        // store {dist,node}
        vector<int> dist(n,INT32_MAX);       // store src to node dist

        // updation for src
        dist[src] = 0;
        st.insert({0,src});
        
        while(!st.empty()){
            // take out minimum dist element
            auto top = *(st.begin());
            int nodeDist = top.first;
            int node = top.second;
            // remove it
            st.erase(st.begin());

            // traverse it's neighbours
            for(auto nbr: adjList[node]){
                // find old and new dist for neighbour
                int newDist = nodeDist + nbr.second;
                int oldDist = dist[nbr.first];
                // if new dist is less than old one then update
                if(newDist < oldDist){
                    
                    // find entry exists in set or not
                    auto result = st.find({oldDist,nbr.first});

                    // if exists remove it
                    if(result != st.end())
                        st.erase(result);
                    
                    // now update in set and dist vec
                    st.insert({newDist,nbr.first});
                    dist[nbr.first] = newDist;
                }
            }
        }
        int cnt = 0;
        for(auto i: dist){
            if(i <= dt)
                cnt++;
        }
        return {src,cnt};
    }
    
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        unordered_map<int,list<pair<int,int>>> adjList;
        makeAdjList(adjList,edges);

        vector<vector<int>> dist;
        int cnt = INT_MAX, ans = INT_MIN;
        for(int i = 0; i < n; i++){
            auto temp = shorestDis(i,n,dt,adjList);
            if(temp[1] < cnt){
                cnt = temp[1];
                ans = temp[0];
            }
            else if(temp[1] == cnt){
                ans = max(ans,temp[0]);
            }
        }
        return ans;
    }
};
```
### Solution 2 - using Floyd-Warshall algorithm
```cpp
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {

        vector<vector<int>> dist(n,vector<int>(n,1e9));
        for(int i = 0; i < n; i++)
            dist[i][i] = 0;
        
        for(auto i: edges){
            dist[i[0]][i[1]] = i[2];
            dist[i[1]][i[0]] = i[2];
        }

        for(int helper = 0; helper < n; helper++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][helper]+dist[helper][j]);
                }
            }
        }

        pair<int,int> temp = {INT_MIN,INT_MAX};
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(dist[i][j] <= dt && i != j)
                    cnt++;
            }
            if(cnt < temp.second)
                temp = {i,cnt};
            else if(cnt == temp.second)
                temp = {max(i,temp.first),cnt};

        }
        return temp.first;
    }
};
```
