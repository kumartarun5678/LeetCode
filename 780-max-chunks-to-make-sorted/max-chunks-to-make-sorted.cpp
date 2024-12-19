class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n =arr.size();
        vector<int>pre(arr.begin(),arr.end());
        vector<int>suff(arr.begin(),arr.end());
        for(int i = 1;i<n;i++){
            pre[i] = max(pre[i],pre[i-1]);
        }
         for(int i = n-2;i>=0;i--){
            suff[i] = min(suff[i],suff[i+1]);
        }
        int cnt= 0;
        for(int i=0;i<n;i++){
            int x = i>0?pre[i-1]:-1;
            int y = suff[i];
            if(x<y){
                cnt++;
            }
        }
        return cnt;
    }
};