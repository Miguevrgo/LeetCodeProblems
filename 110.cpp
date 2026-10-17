#include <algorithm>
#include <cstdlib>

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
    bool isBalanced(TreeNode *root) {
        auto left_depth = maxDepth(root->left);
        auto right_depth = maxDepth(root->right);

        if (std::abs(right_depth - left_depth) > 1) {
            return false;
        } else {
            return isBalanced(root->left) && isBalanced(root->right);
        }
    }

    auto maxDepth(TreeNode *root) -> int {
        if (root == nullptr) {
            return 0;
        } else {
            return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
        }
    }

    auto dfs(TreeNode *root) -> std::pair<bool, int> {
        if (root == nullptr) {
            return {true, 0};
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        bool is_balanced = (left.first && right.first) && (std::abs(left.second - right.second));
        int height = 1 + std::max(left.second, right.second);

        return {is_balanced, height};
    }
};
