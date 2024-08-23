class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        helper(0, s, path, res);
        return res;
    }

    void helper(int i, string s, vector<string>& path, vector<vector<string>>& res) {
        if (i == s.size()) {
            res.push_back(path);
            return;
        }
        for (int j = i; j < s.size(); j++) {
            if (ispalim(s, i, j)) {
                path.push_back(s.substr(i, j - i + 1));
                helper(j + 1, s, path, res);
                path.pop_back();
            }
        }
    }

    bool ispalim(string s, int i, int j) {
        while (i <= j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
};
