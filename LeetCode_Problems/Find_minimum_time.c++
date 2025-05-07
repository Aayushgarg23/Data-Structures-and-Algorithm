// There is a dungeon with n x m rooms arranged as a grid.

// You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes exactly one second.

// Return the minimum time to reach the room (n - 1, m - 1).

// Two rooms are adjacent if they share a common wall, either horizontally or vertically.

 

// Example 1:

// Input: moveTime = [[0,4],[4,4]]

// Output: 6

// Explanation:

// The minimum time required is 6 seconds.

// At time t == 4, move from room (0, 0) to room (1, 0) in one second.
// At time t == 5, move from room (1, 0) to room (1, 1) in one second.
// Example 2:

// Input: moveTime = [[0,0,0],[0,0,0]]

// Output: 3

// Explanation:

// The minimum time required is 3 seconds.

// At time t == 0, move from room (0, 0) to room (1, 0) in one second.
// At time t == 1, move from room (1, 0) to room (1, 1) in one second.
// At time t == 2, move from room (1, 1) to room (1, 2) in one second.
// Example 3:

// Input: moveTime = [[0,1],[1,2]]

// Output: 3

 

// Constraints:

// 2 <= n == moveTime.length <= 50
// 2 <= m == moveTime[i].length <= 50
// 0 <= moveTime[i][j] <= 109


class Solution {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
           
            int n = moveTime.size();
            int m = moveTime[0].size();
            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
            vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
            vector<int> di = {0, 1, 0, -1};
            vector<int> dj = {1, 0, -1, 0};
            dist[0][0] = 0;
            pq.emplace(0, 0, 0);
            
            while (!pq.empty()) {
                auto [time, i, j] = pq.top();
                pq.pop();
                if (time > dist[i][j]) continue;
                if (i == n-1 && j == m-1) return time;
                for (int k = 0; k < 4; k++) {
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        int nextTime = max(time + 1, moveTime[ni][nj] + 1);
                        if (nextTime < dist[ni][nj]) {
                            dist[ni][nj] = nextTime;
                            pq.emplace(nextTime, ni, nj);
                        }
                    }
                }
            }
            return dist[n-1][m-1];
        }
    };