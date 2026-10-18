#include <vector>
#include <iostream>

class Solution {
private:
    long long MOD = 1e9 + 7;
    std::vector<std::vector<long long>> table;

    // Helper function to calculate combination C(n, k) modulo 1e9 + 7
    long long combination(int n, int k) {
        if (k > n || k < 0) return 0;
        if (k == 0 || k == n) return 1;
        if (table[n][k] != -1) return table[n][k];
        return table[n][k] = (combination(n - 1, k - 1) + combination(n - 1, k)) % MOD;
    }

    // Recursive helper to count ways for a given subtree
    long long solve(const std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        int root = nums[0];
        std::vector<int> leftSubtree, rightSubtree;

        // Partition elements into left and right subtrees
        for (int i = 1; i < n; ++i) {
            if (nums[i] < root) {
                leftSubtree.push_back(nums[i]);
            } else {
                rightSubtree.push_back(nums[i]);
            }
        }

        long long leftWays = solve(leftSubtree);
        long long rightWays = solve(rightSubtree);

        int leftSize = leftSubtree.size();
        int rightSize = rightSubtree.size();

        // Ways to interleave left and right elements is C(leftSize + rightSize, leftSize)
        long long ways = combination(leftSize + rightSize, leftSize);

        // Multiply by the combinations of ways from subtrees
        ways = (ways * leftWays) % MOD;
        ways = (ways * rightWays) % MOD;

        return ways;
    }

public:
    int numOfWays(std::vector<int>& nums) {
        int n = nums.size();
        // Initialize Pascal's Triangle table for combinations
        table = std::vector<std::vector<long long>>(n + 1, std::vector<long long>(n + 1, -1));

        // Subtract 1 because the problem asks for ways to *reorder* the array 
        // (excluding the original ordering itself).
        return (solve(nums) - 1 + MOD) % MOD;
    }
};