 class Solution {
   public:
     int countSubsequences(string& s, int n) {
         const int MOD = 1e9 + 7;
         vector<int> dp(n, 0);

         for (char ch : s) {
             int digit = ch - '0';
             vector<int> next_dp = dp;

             // Single-digit subsequence starting at current character
             next_dp[digit % n] = (next_dp[digit % n] + 1) % MOD;

             // Appending current digit to previously formed subsequences
             for (int r = 0; r < n; ++r) {
                 if (dp[r] > 0) {
                     int new_rem = (r * 10 + digit) % n;
                     next_dp[new_rem] = (next_dp[new_rem] + dp[r]) % MOD;
                 }
             }

             dp = move(next_dp);
         }

         return dp[0];
     }
 };