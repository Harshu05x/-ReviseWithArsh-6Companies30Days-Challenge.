// Leetcode 216. Combination Sum III

// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
// --> Only numbers 1 through 9 are used.
// --> Each number is used at most once.
// Return a list of all possible valid combinations. 
// The list must not contain the same combination twice, and the combinations may be returned in any order.

// Example 1:
//     Input: k = 3, n = 7
//     Output: [[1,2,4]]
//     Explanation:
//         1 + 2 + 4 = 7
//         There are no other valid combinations.

class Solution {
public:
    vector<vector<int>> ans;
    void findCombinationSum(int& k, int n, vector<int>& temp, int index){
        if(temp.size() == k){
            if(n == 0) ans.push_back(temp);
            return;
        }

        for(int i = index; i <= 9; i++){
            if(i <= n){
                temp.push_back(i);
                findCombinationSum(k,n-i,temp,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        int sum = 0;
        int index = 0;

        findCombinationSum(k,n,temp,1);

        return ans;
    }
};
