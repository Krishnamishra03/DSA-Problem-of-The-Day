 class Solution {
   public:
     int minMoves(vector<int>& arr) {
         int n = arr.size();
         vector<int> dp(n + 1, 0);
         int max_len = 0;

         for (int x : arr) {
             dp[x] = dp[x - 1] + 1;
             max_len = max(max_len, dp[x]);
         }

         return n - max_len;
     }
 };