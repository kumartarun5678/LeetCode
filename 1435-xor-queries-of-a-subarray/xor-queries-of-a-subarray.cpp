class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>xorr(n,0);
        xorr[0] = arr[0];
        for(int i=1;i<n;i++){
            xorr[i] = xorr[i-1]^arr[i];
        }

        vector<int>res;

        for(vector<int>&q:queries){
            int l = q[0];
            int r= q[1];

            int val = xorr[r]^(l==0?0:xorr[l-1]);
            res.push_back(val);
        }
        return res;
    }
};