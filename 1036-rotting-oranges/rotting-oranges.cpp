class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int freshOranges = 0;
        queue<pair<int, int>> q;

        // Initial processing
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int minutes = 0;
        while (!q.empty() && freshOranges > 0) {
            int size = q.size();
            minutes++;

            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();

                for (auto [dx, dy] : directions) {
                    int newX = x + dx;
                    int newY = y + dy;
                    if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2; 
                        freshOranges--;  
                        q.push({newX, newY}); 
                    }
                }
            }
        }

        if (freshOranges > 0) {
            return -1;
        }

        return minutes;
    }
};
