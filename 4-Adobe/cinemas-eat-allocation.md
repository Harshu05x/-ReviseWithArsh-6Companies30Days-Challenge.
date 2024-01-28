# Cinema Seat Allocation

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/cinema-seat-allocation/description/)

A cinema has n rows of seats, numbered from 1 to n and there are ten seats in each row, labelled from 1 to 10 as 
shown in the figure above.

Given the array reservedSeats containing the numbers of seats already reserved, for example, reservedSeats[i] = 
[38] means the seat located in row 3 and labelled with 8 is already reserved.

Return the maximum number of four-person groups you can assign on the cinema seats. A four-person group occupies 
four adjacent seats in one single row. Seats across an aisle (such as [3,3] and [3,4]) are not considered to be 
adjacent, but there is an exceptional case on which an aisle split a four-person group, in that case, the aisle 
split a four-person group in the middle, which means to have two people on each side.

### Sample Input
```
n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
```
### Sample Output
```
4

Explanation: The figure above shows the optimal allocation for four groups, where seats mark with blue are already reserved and contiguous seats mark with orange are for one group.
```

### Solution
```cpp
class Solution {
int fun(int start,int end){       
    if(2>=start && 9<=(end))  
        return 2;
    else if(2>=start && 5<=(end))
        return 1;            
    else if(6>=start && 9<=(end))
        return 1;           
    else if(4>=start && 7<=(end))
        return 1;           

    return 0;      
} 
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& a) {
        int ans=0;
        
        sort(a.begin(),a.end());
        
        int present=a[0][0];
        int last=1;
        
        set<int> st;  
        st.insert(present);
        
        for(int i=0;i<a.size();i++){
            if(present==a[i][0]){         
                ans+=fun(last,(a[i][1]-1));
                last=a[i][1]+1;

            }
            else {               
                ans+= fun(last,10);
                ans+=fun(1,a[i][1]-1);
                st.insert(a[i][0]);
                present=a[i][0];
                last=a[i][1]+1;
            }
        }
        
        ans+= fun(last,10);
        if(st.size()!=n) ans+=(2*(n-st.size())); 
        return ans;
        
    }
};
```
