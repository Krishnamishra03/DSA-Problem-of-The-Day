class Solution {
  public:
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
        int n = mat.size();
        int m = mat[0].size();
        int len = word.length();

        vector<vector<int>> ans;

        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] != word[0]) continue;

                // If the word has length 1, add coordinate and move to the next cell
                if (len == 1) {
                    ans.push_back({i, j});
                    continue;
                }

                // Check all 8 directions
                for (int dir = 0; dir < 8; ++dir) {
                    int r = i + dx[dir];
                    int c = j + dy[dir];
                    int k = 1;

                    while (k < len) {
                        if (r < 0 || r >= n || c < 0 || c >= m || mat[r][c] != word[k]) {
                            break;
                        }
                        r += dx[dir];
                        c += dy[dir];
                        k++;
                    }

                    // If matched fully in this direction, record cell once and stop checking other directions
                    if (k == len) {
                        ans.push_back({i, j});
                        break; 
                    }
                }
            }
        }

        return ans;
    }
};