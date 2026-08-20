/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  private:
    int helper(Node* root, int &max_diff) {
        if (!root) return INT_MAX;

        // A leaf node has no descendants, so return its own value
        if (!root->left && !root->right) {
            return root->data;
        }

        // Find the minimum value in left and right subtrees
        int left_min = helper(root->left, max_diff);
        int right_min = helper(root->right, max_diff);

        int min_descendant = std::min(left_min, right_min);

        // Update the maximum difference (Ancestor - Descendant)
        max_diff = std::max(max_diff, root->data - min_descendant);

        // Return minimum value in the subtree rooted at current node
        return std::min(root->data, min_descendant);
    }

  public:
    int maxDiff(Node* root) {
        int max_diff = INT_MIN;
        helper(root, max_diff);
        return max_diff;
    }
};