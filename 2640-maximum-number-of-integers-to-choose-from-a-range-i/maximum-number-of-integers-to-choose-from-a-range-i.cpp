class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(banned.begin(), banned.end());
        int sum = 0;
        int cnt = 0;

        for (int i = 1; i <= n; i++) {
            if (st.count(i)) {
                continue;
            }
            if (sum + i <= maxSum) {
                cnt++;
                sum += i;
            } else {
                break;
            }
        }
        return cnt;
    }
};