 class Solution {
   public:
     int palindromicStrings(int n, int k) {
         long long total = 0;
         long long MOD = 1e9 + 7;

         for (int len = 1; len <= n; ++len) {
             int distinct_needed = (len + 1) / 2;

             if (distinct_needed <= k) {
                 long long ways = 1;
                 for (int i = 0; i < distinct_needed; ++i) {
                     ways = (ways * (k - i)) % MOD;
                 }
                 total = (total + ways) % MOD;
             }
         }

         return total;
     }
 };