 class Solution {
    struct Node {
        int r, c, rem_u, rem_d;
    };

  public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Boundary and obstacle check for starting position
        if (r < 0 || r >= n || c < 0 || c >= m || mat[r][c] == '#') {
            return 0;
        }

        // Stores the maximum remaining 'u' and 'd' for each cell
        vector<vector<int>> max_u(n, vector<int>(m, -1));
        vector<vector<int>> max_d(n, vector<int>(m, -1));

        queue<Node> q;
        q.push({r, c, u, d});
        max_u[r][c] = u;
        max_d[r][c] = d;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            Node curr = q.front();
            q.pop();

            // If a better path to this cell has already been processed, skip
            if (curr.rem_u < max_u[curr.r][curr.c] && curr.rem_d < max_d[curr.r][curr.c]) {
                continue;
            }

            for (int i = 0; i < 4; i++) {
                int nr = curr.r + dr[i];
                int nc = curr.c + dc[i];
                int nu = curr.rem_u - (i == 0 ? 1 : 0);
                int nd = curr.rem_d - (i == 1 ? 1 : 0);

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == '.' && nu >= 0 && nd >= 0) {
                    if (nu > max_u[nr][nc] || nd > max_d[nr][nc]) {
                        max_u[nr][nc] = max(max_u[nr][nc], nu);
                        max_d[nr][nc] = max(max_d[nr][nc], nd);
                        q.push({nr, nc, nu, nd});
                    }
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (max_u[i][j] != -1 || max_d[i][j] != -1) {
                    count++;
                }
            }
        }

        return count;
    }
};