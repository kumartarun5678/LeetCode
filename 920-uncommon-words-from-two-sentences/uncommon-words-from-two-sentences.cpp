class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mpp;
        string temp = s1+' '+s2;
        string p = "";
        vector<string>ans;

        for(int i=0;i<temp.size();i++){
            if(temp[i] == ' '){
                mpp[p]++;
                p = "";
            }
            else{
                p+=temp[i];
            }
        }
        mpp[p]++;
        for(auto &it:mpp){
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};