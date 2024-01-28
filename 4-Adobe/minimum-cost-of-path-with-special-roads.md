# Minimum Cost of a Path With Special Roads

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/description/)

You are given an array start where start = [startX, startY] represents your initial position (startX, startY) in a 
2D space. You are also given the array target where target = [targetX, targetY] represents your target position
 (targetX, targetY).

The cost of going from a position (x1, y1) to any other position in the space (x2, y2) is |x2 - x1| + |y2 - y1|.

There are also some special roads. You are given a 2D array specialRoads where specialRoads[i] = [x1i, y1i, x2i, 
y2i, costi] indicates that the ith special road can take you from (x1i, y1i) to (x2i, y2i) with a cost equal to 
costi. You can use each special road any number of times.

Return the minimum cost required to go from (startX, startY) to (targetX, targetY).

### Sample Input
```
start = [1,1], target = [4,5], specialRoads = [[1,2,3,3,2],[3,4,4,5,1]]
```
### Sample Output
```
 5

Explanation: The optimal path from (1,1) to (4,5) is the following:
- (1,1) -> (1,2). This move has a cost of |1 - 1| + |2 - 1| = 1.
- (1,2) -> (3,3). This move uses the first special edge, the cost is 2.
- (3,3) -> (3,4). This move has a cost of |3 - 3| + |4 - 3| = 1.
- (3,4) -> (4,5). This move uses the second special edge, the cost is 1.
So the total cost is 1 + 2 + 1 + 1 = 5.
It can be shown that we cannot achieve a smaller total cost than 5.
```

### Solution
```cpp
class Solution {
public:
int dp[402][402];
int f(vector<vector<int>>&s,int i,int prev,int a1,int b1,int a2,int b2){
    if(i==s.size()){
     if(prev==-1){
         return abs(a2-a1)+abs(b2-b1);
     }
        return abs(a2-s[prev][2])+abs(b2-s[prev][3])+s[prev][4];
     }
     if(dp[i][prev+1]!=-1){return dp[i][prev+1];}
    int nt=f(s,i+1,prev,a1,b1,a2,b2);
    int t=0;
    if(prev==-1){
       t=abs(a1-s[i][0])+abs(b1-s[i][1])+f(s,i+1,i,a1,b1,a2,b2); 
    }
    else{
          t=abs(s[prev][2]-s[i][0])+abs(s[prev][3]-s[i][1])+s[prev][4]+f(s,i+1,i,a1,b1,a2,b2);
    }
    return dp[i][prev+1]=min(nt,t);
    }

int minimumCost(vector<int>& s1, vector<int>&t, vector<vector<int>>&s){
    vector<vector<int>>v=s;
    for(int i=0;i<s.size();i++){
        v.push_back(s[i]);
    }
    memset(dp,-1,sizeof(dp));
    return f(v,0,-1,s1[0],s1[1],t[0],t[1]);
    
}
};
```
