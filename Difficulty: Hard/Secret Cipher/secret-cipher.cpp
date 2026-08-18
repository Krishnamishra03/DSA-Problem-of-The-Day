 class Solution {
   private:
     vector<int> calculateZ(const string &s) {
         int n = s.length();
         vector<int> z(n, 0);
         int l = 0, r = 0;
         for (int i = 1; i < n; i++) {
             if (i <= r) {
                 z[i] = min(r - i + 1, z[i - l]);
             }
             while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                 z[i]++;
             }
             if (i + z[i] - 1 > r) {
                 l = i;
                 r = i + z[i] - 1;
             }
         }
         return z;
     }

   public:
     string compress(string &s) {
         int n = s.length();
         if (n == 0) return "";

         vector<int> z = calculateZ(s);
         string result = "";

         int i = n - 1;
         while (i >= 0) {
             int len = i + 1;
             if (len % 2 == 0 && z[len / 2] >= len / 2) {
                 result.push_back('*');
                 i = (len / 2) - 1;
             } else {
                 result.push_back(s[i]);
                 i--;
             }
         }

         reverse(result.begin(), result.end());
         return result;
     }
 };