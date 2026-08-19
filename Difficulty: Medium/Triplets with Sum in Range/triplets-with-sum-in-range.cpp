 class Solution {
   private:
     int countTripletsLessThanOrEqual(const vector<int>& arr, int val) {
         int n = arr.size();
         int count = 0;

         for (int i = 0; i < n - 2; i++) {
             int left = i + 1;
             int right = n - 1;

             while (left < right) {
                 int sum = arr[i] + arr[left] + arr[right];
                 if (sum <= val) {
                     count += (right - left);
                     left++;
                 } else {
                     right--;
                 }
             }
         }
         return count;
     }

   public:
     int countTriplets(vector<int> &arr, int l, int r) {
         sort(arr.begin(), arr.end());
         return countTripletsLessThanOrEqual(arr, r) - countTripletsLessThanOrEqual(arr, l - 1);
     }
 };