class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        unordered_set<int> st;
        int ans = 1;
        int cnt=0;
        for(int i = 0;i<n;i++){
            st.insert(nums[i]);
        }

        for(auto it : st){
            if (st.find(it - 1) == st.end()) {
                cnt = 1;
                int x=it;
                while(st.find(x+1) != st.end()){
                    x = x+1;
                    cnt++;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};