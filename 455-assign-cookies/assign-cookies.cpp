class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        int i = 0,j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i<m && j<n){
            if(g[j]<=s[i]){
                j++;
            }
            i++;
        }
        return j;
    }
};