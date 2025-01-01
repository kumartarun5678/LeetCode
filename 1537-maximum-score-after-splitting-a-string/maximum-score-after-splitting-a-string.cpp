class Solution {
public:
    int maxScore(string s) {
        int total1 = 0, left0 = 0, left1 = 0, maxScore = 0;
        for (char c : s) {
            if (c == '1') {
                total1++;
            }
        }

        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '0') {
                left0++;
            } else {
                left1++;
            }
            
            int right1 = total1 - left1;
            maxScore = max(maxScore, left0 + right1);
        }

        return maxScore;
    }
};