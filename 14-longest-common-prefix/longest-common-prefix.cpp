class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string ans = "";
        int n = strs.size();
        for (int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];
            bool match = true;
            for (int j = 1; j < n; j++) {
                if (i >= strs[j].size() || strs[j][i] != ch) {
                    match = false;
                    break;
                }
            }
            if (!match) {
                break;
            } else {
                ans.push_back(ch);
            }
        }

        return ans;
    }
};
