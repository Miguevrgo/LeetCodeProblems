#include <stack>
#include <utility>
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
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        std::stack<TreeNode *> stack;
        stack.push(root);

        while (!stack.empty()) {
            auto *next_node = stack.top();
            stack.pop();

            std::swap(next_node->left, next_node->right);
            if (next_node->left != nullptr) {
                stack.push(next_node->left);
            }
            if (next_node->right != nullptr) {
                stack.push(next_node->right);
            }
        }

        return root;
    }
};
