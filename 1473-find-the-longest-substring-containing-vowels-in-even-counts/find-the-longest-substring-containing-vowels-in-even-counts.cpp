class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        unordered_map<int,int> mpp;
        int mask = 0;
        mpp[mask] = -1;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i] == 'a'){
                mask = (mask^(1<<0));
            }
            else if(s[i] == 'e'){
                mask = (mask^(1<<1));
            }
            else if(s[i] == 'i'){
                mask = (mask^(1<<2));
            }
            else if(s[i] == 'o'){
                mask = (mask^(1<<3));
            }
            else if(s[i] == 'u'){
                mask = (mask^(1<<4));
            }
            if(mpp.find(mask) != mpp.end()){
                ans = max(ans, i-mpp[mask]);
            }
            else{
                mpp[mask] = i;
            }
        }
        return ans;
    }
};