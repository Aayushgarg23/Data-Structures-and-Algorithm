class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({row, col});
        visited[row][col] = 1;

        // All 8 directions
        int dR[] = {-1,-1,-1,0,0,1,1,1};
        int dC[] = {-1,0,1,-1,1,-1,0,1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            // Check all 8 neighbors
            for (int k = 0; k < 8; k++) {
                int nr = r + dR[k];
                int nc = c + dC[k];

                // Condition explained above
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    !visited[nr][nc] &&
                    grid[nr][nc] == 'L') 
                {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

public:
    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Traverse whole grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Found a new island start
                if (!visited[i][j] && grid[i][j] == 'L') {
                    cnt++;                     // new island found
                    bfs(i, j, visited, grid); // mark whole island
                }
            }
        }
        return cnt;
    }
};

// time complexity: O(N*M) where N and M are number of rows and columns respectively bcz we are traversing whole grid once 
// space complexity: O(N*M) for visited array and O(min(N,M)) for queue in bfs in worst case bcz at max we can have min(N,M) nodes in queue at a time.