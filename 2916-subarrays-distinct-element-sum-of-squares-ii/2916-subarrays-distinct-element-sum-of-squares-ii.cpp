#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    static const int MOD = 1e9 + 7;
    
    struct Node {
        long long sum_sq = 0;
        long long sum = 0;
        long long lazy = 0;
    };
    
    vector<Node> tree;
    
    void push(int node, int l, int r) {
        if (tree[node].lazy != 0) {
            long long lz = tree[node].lazy;
            int mid = (l + r) / 2;
            
            // Left child
            int left = 2 * node;
            tree[left].sum_sq = (tree[left].sum_sq + 2 * lz * tree[left].sum + lz * lz * (mid - l + 1)) % MOD;
            tree[left].sum = (tree[left].sum + lz * (mid - l + 1)) % MOD;
            tree[left].lazy = (tree[left].lazy + lz) % MOD;
            
            // Right child
            int right = 2 * node + 1;
            tree[right].sum_sq = (tree[right].sum_sq + 2 * lz * tree[right].sum + lz * lz * (r - mid)) % MOD;
            tree[right].sum = (tree[right].sum + lz * (r - mid)) % MOD;
            tree[right].lazy = (tree[right].lazy + lz) % MOD;
            
            tree[node].lazy = 0;
        }
    }
    
    void update(int node, int l, int r, int ql, int qr, long long val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            tree[node].sum_sq = (tree[node].sum_sq + 2 * val * tree[node].sum + val * val * (r - l + 1)) % MOD;
            tree[node].sum = (tree[node].sum + val * (r - l + 1)) % MOD;
            tree[node].lazy = (tree[node].lazy + val) % MOD;
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr, val);
        update(2 * node + 1, mid + 1, r, ql, qr, val);
        
        tree[node].sum = (tree[2 * node].sum + tree[2 * node + 1].sum) % MOD;
        tree[node].sum_sq = (tree[2 * node].sum_sq + tree[2 * node + 1].sum_sq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree.assign(4 * n + 1, Node());
        
        unordered_map<int, int> last_occ;
        long long total_sum_sq = 0;
        long long current_total = 0;
        
        for (int j = 0; j < n; ++j) {
            int last = last_occ.count(nums[j]) ? last_occ[nums[j]] : -1;
            
            // Update range [last + 1, j] by adding 1
            update(1, 0, n - 1, last + 1, j, 1);
            
            last_occ[nums[j]] = j;
            
            // tree[1].sum_sq holds the sum of squares of distinct counts for all subarrays ending at j
            total_sum_sq = (total_sum_sq + tree[1].sum_sq) % MOD;
        }
        
        return total_sum_sq;
    }
};