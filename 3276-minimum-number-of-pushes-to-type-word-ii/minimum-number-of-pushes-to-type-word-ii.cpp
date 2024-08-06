class Solution {
public:
    int minimumPushes(string word) {
        vector<int> Freq(26, 0);
        for (char ch : word) {
            Freq[ch - 'a']++;
        }
        
        sort(Freq.rbegin(), Freq.rend());
        
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (Freq[i] == 0) break;
            cnt += (i / 8 + 1) * Freq[i];
        }
        
        return cnt;
    }
};