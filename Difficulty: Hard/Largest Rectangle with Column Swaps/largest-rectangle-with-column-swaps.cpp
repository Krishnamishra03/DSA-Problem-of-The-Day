 class Solution {
   public:
     int maxArea(vector<vector<int>>& mat) {
         int n = mat.size();
         if (n == 0) return 0;
         int m = mat[0].size();

         // Step 1: Precompute consecutive 1s vertically in-place
         for (int j = 0; j < m; j++) {
             for (int i = 1; i < n; i++) {
                 if (mat[i][j] == 1) {
                     mat[i][j] += mat[i - 1][j];
                 }
             }
         }

         int max_area = 0;

         // Step 2: Use counting sort on column heights for each row
         for (int i = 0; i < n; i++) {
             vector<int> count(n + 1, 0);

             for (int j = 0; j < m; j++) {
                 count[mat[i][j]]++;
             }

             int col_idx = 0;
             // Iterate from largest height down to 1
             for (int h = n; h >= 1; h--) {
                 while (count[h] > 0) {
                     col_idx++;
                     max_area = max(max_area, h * col_idx);
                     count[h]--;
                 }
             }
         }

         return max_area;
     }
 };