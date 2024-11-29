using info = tuple<int, short, short>; 
const static int d[5] = {0, 1, 0, -1, 0};
class Solution {
public:
    inline static bool isOutside(short i, short j, short n, short m) {
        return i < 0 || i >= n || j < 0 || j >= m;
    }

    int minimumTime(vector<vector<int>>& grid) {
        if (grid[1][0]>1 && grid[0][1]>1)  return -1;
    
        short n = grid.size(), m = grid[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        priority_queue<info, vector<info>, greater<info>> pq;
        pq.emplace(0, 0, 0);
        time[0][0] = 0;
        while (!pq.empty()) {
            auto [t, i, j] = pq.top();
            pq.pop();
            if (i == n - 1 && j == m - 1)
                return t;
            for (int a = 0; a < 4; a++) {
                int r = i + d[a], s = j + d[a + 1];
                if (isOutside(r, s, n, m)) continue;
                int w=((grid[r][s]-t)&1)?0:1;
                int nextTime = max(t+1, grid[r][s]+w); 
                if (nextTime < time[r][s]) {
                    time[r][s] = nextTime;
                    pq.emplace(nextTime, r, s);
                }
            }
        }

        return -1;
    }
};
