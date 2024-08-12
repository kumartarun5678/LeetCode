class Solution {
public:
    void helper(int in, vector<int>& nums,vector<int>& num, vector<vector<int>>& ans){
        int n = nums.size();
        ans.push_back(num);
        for(int i = in;i<n;i++){
            if(i!=in && nums[i]==nums[i-1]){
                continue;
            }
            num.push_back(nums[i]);
            helper(i+1,nums,num,ans);
            num.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>num;
        sort(nums.begin(),nums.end());
        helper(0,nums,num,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};