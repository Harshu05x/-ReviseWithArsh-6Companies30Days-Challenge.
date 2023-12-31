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
