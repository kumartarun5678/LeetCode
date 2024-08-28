class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        typedef pair<int,int>p;
        unordered_map<int ,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        
        priority_queue<p,vector<p>, greater<p>>pq;
        for(auto &it:mp){
            int val = it.first;
            int freq = it.second;
            pq.push({freq,val});
            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};