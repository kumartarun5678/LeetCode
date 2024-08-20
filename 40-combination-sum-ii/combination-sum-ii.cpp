class Solution {
public:
    void helper(int i, int target, vector<int>& arr, vector<vector<int>>& ans,
                vector<int>& ds) {

        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int j = i; j < arr.size(); j++) {
            if (j > i && arr[j] == arr[j - 1]) continue;
            if (arr[j] > target) break; 
            ds.push_back(arr[j]);
            helper(j + 1, target - arr[j], arr, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end()); 
        helper(0, target, candidates, ans, ds);
        return ans;
    }
};