 class Solution {
   private:
     Node* findLCA(Node* root, int p, int q) {
         if (!root || root->data == p || root->data == q)
             return root;

         Node* left = findLCA(root->left, p, q);
         Node* right = findLCA(root->right, p, q);

         if (left && right) return root;
         return left ? left : right;
     }

     bool getPath(Node* root, int target, string &path) {
         if (!root) return false;
         if (root->data == target) return true;

         // Try left
         path.push_back('L');
         if (getPath(root->left, target, path)) return true;
         path.pop_back();

         // Try right
         path.push_back('R');
         if (getPath(root->right, target, path)) return true;
         path.pop_back();

         return false;
     }

   public:
     int numberOfTurns(Node* root, int p, int q) {
         if (!root || p == q) return -1;

         Node* lca = findLCA(root, p, q);
         if (!lca) return -1;

         string pathP = "", pathQ = "";

         // If LCA is one of the target nodes
         if (lca->data == p) {
             getPath(lca, q, pathQ);
             int turns = 0;
             for (size_t i = 1; i < pathQ.size(); i++) {
                 if (pathQ[i] != pathQ[i - 1]) turns++;
             }
             return turns == 0 ? -1 : turns;
         }

         if (lca->data == q) {
             getPath(lca, p, pathP);
             int turns = 0;
             for (size_t i = 1; i < pathP.size(); i++) {
                 if (pathP[i] != pathP[i - 1]) turns++;
             }
             return turns == 0 ? -1 : turns;
         }

         // When LCA is an intermediate ancestor
         getPath(lca, p, pathP);
         getPath(lca, q, pathQ);

         int turns = 1; // +1 turn for crossing through LCA (left branch <-> right branch)

         for (size_t i = 1; i < pathP.size(); i++) {
             if (pathP[i] != pathP[i - 1]) turns++;
         }

         for (size_t i = 1; i < pathQ.size(); i++) {
             if (pathQ[i] != pathQ[i - 1]) turns++;
         }

         return turns == 0 ? -1 : turns;
     }
 };