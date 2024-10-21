class Solution {
public:
    void helper(int i,unordered_set<string>&st, int &maxcnt,int currcnt , string s){
        if(currcnt + (s.length()-i)<=maxcnt){
            return;
        }
        if(i>=s.length()){
            maxcnt = max(maxcnt,currcnt);
            return;
        }
        for(int j=i;j<s.length();j++){
            string str = s.substr(i,j-i+1);
            if(st.find(str) == st.end()){
                st.insert(str);
                helper(j+1,st,maxcnt,currcnt+1,s);
                st.erase(str);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        int maxcnt = 0;
        int currcnt = 0;
        int i = 0;
        helper(i,st,maxcnt,currcnt,s);
        return maxcnt;
    }
};