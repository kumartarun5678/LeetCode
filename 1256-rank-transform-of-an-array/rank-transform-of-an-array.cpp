class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans;
        if(n==0){
            return ans;
        }
        set<int>st(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        int rank = 1;
        for(const int &it:st){
            mp[it] = rank++;
        }
        for(int &it:arr){
            ans.push_back(mp[it]);
        }
        return ans;
    }
};