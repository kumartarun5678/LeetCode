class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>lo(26,0);
        vector<int>up(26,0);

        for(int i =0;i<s.size();i++){
            if(s[i]>='a'){
                lo[s[i] - 'a']++;
            }
            else{
                up[s[i] - 'A']++;
            }
        }

        int cnt = 0;
        bool odd= 0;
        for(int i=0;i<26;i++){
            if(lo[i] %2 ==0){
                cnt+=lo[i];
            }
            else{
                cnt+=lo[i]-1;
                odd = 1;
            }
            if(up[i]%2 ==0){
                cnt += up[i];
            }
            else{
                cnt += up[i] -1;
                odd=1;
            }
        }
        return cnt+odd;
    }
};