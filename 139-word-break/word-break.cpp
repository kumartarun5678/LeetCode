class Solution {
public:
    unordered_set<string>st;
    int t[301];
    bool helper(int ind, string s){
        int n = s.size();
        if(ind == n){
            return true;
        }
        if(t[ind] != -1){
            return t[ind];
        }
        if(st.find(s) != st.end()){
            return true;
        }

        for(int i = 1;i<=n;i++){
            string tmp = s.substr(ind,i);
            if(st.find(tmp)!= st.end() && helper(ind+i,s)){
                return t[i] =  true;
            }          
        }

        return t[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
         int n = s.size(); 
        for(string &w:wordDict){
            st.insert(w);
        }
        memset(t,-1, sizeof(t));
        return helper(0,s);
    }
};