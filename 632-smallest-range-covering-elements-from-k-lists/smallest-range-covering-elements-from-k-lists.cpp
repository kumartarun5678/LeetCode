class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue< vector<int>, vector<vector<int>>,greater<vector<int>>>pq;
        int maxe = INT_MIN;

        for(int i=0;i<n;i++){
            pq.push({nums[i][0],i,0});
            maxe = max(maxe,nums[i][0]);
        }

        vector<int> ans = {-1000000,1000000};
        while(!pq.empty()){
            vector<int> curr=pq.top();
            pq.pop();
            int mine =curr[0];
            int list = curr[1];
            int ind = curr[2];

            if(maxe-mine<ans[1]-ans[0]){
                ans[0] = mine;
                ans[1] = maxe;
            } 

            if(ind+1<nums[list].size()){
                int next = nums[list][ind+1];
                pq.push({next,list,ind+1});
                maxe = max(maxe,next);
            }
            else{
                break;
            }
        }
        return ans;
    }
};