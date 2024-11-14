class Solution {
public:
    bool helper(int n, vector<int>&quantities,int shops){
        for(int &p:quantities){
            shops -= (p+n-1)/n;
            if(shops<0){
                return false;
            }
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        int l = 1;
        int r = *max_element(quantities.begin(),quantities.end());
        int ans = 0;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(helper(mid,quantities,n)){
                ans = mid;
                r= mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};