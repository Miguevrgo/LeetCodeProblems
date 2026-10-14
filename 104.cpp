
#include <algorithm>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    auto maxDepth(TreeNode *root) -> int {
        if (root == nullptr) {
            return 0;
        } else {
            return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
        }
    }
};
