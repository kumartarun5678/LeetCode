#include <vector>
using namespace std;

class Solution {
public:
    vector<int> binary(int num) {
        vector<int> bin;
        while (num > 0) {
            bin.push_back(num % 2);
            num /= 2;
        }
        
        reverse(bin.begin(), bin.end());
        
        return bin;
    }

    int minBitFlips(int start, int goal) {
        vector<int> s = binary(start);
        vector<int> g = binary(goal);
        int n = s.size(), m = g.size();
        if (n < m) {
            s.insert(s.begin(), m - n, 0);
        } else if (m < n) {
            g.insert(g.begin(), n - m, 0);
        }

        int cnt = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != g[i]) {
                cnt++;
            }
        }

        return cnt;
    }
};
