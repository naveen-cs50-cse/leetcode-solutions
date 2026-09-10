class Solution {
private:
    int matchingNodes = 0;

    // Returns {sum_of_subtree, total_nodes_in_subtree}
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        int currentSum = left.first + right.first + node->val;
        int currentCount = left.second + right.second + 1;

        if (currentSum / currentCount == node->val) {
            matchingNodes++;
        }

        return {currentSum, currentCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return matchingNodes;
    }
};