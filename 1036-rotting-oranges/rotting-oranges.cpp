
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;
        int time = 0;

        // Step 1: Count fresh and push rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // Step 2: BFS
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty() && fresh > 0) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                // 4 directions
                for (int d = 0; d < 4; d++) {

                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx >= 0 && ny >= 0 &&
                        nx < n && ny < m &&
                        grid[nx][ny] == 1) {

                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }

            time++;
        }

        if (fresh == 0)
            return time;

        return -1;
    }
};
