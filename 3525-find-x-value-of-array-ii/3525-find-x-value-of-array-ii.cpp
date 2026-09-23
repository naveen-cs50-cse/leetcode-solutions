#include <vector>
#include <array>
#include <algorithm>

using namespace std;

struct Node {
    int prod = 1;
    array<int, 5> cnt{}; // Fixed size 5 since k <= 5

    Node() = default;
};

class SegmentTree {
    int n;
    int k;
    vector<Node> tree;

    // Fast merge in-place to avoid copying
    Node merge(const Node& left, const Node& right) const {
        Node res;
        res.prod = (left.prod * right.prod) % k;

        // Copy left counts
        res.cnt = left.cnt;

        // Add shifted right counts
        for (int r = 0; r < k; ++r) {
            if (right.cnt[r] > 0) {
                int new_rem = (left.prod * r) % k;
                res.cnt[new_rem] += right.cnt[r];
            }
        }

        return res;
    }

    void build(const vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            int rem = nums[start] % k;
            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(nums, node * 2, start, mid);
        build(nums, node * 2 + 1, mid + 1, end);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            int rem = val % k;
            tree[node].prod = rem;
            tree[node].cnt.fill(0);
            tree[node].cnt[rem] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(node * 2, start, mid, idx, val);
        } else {
            update(node * 2 + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int start, int end, int l, int r) const {
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        if (r <= mid) {
            return query(node * 2, start, mid, l, r);
        }
        if (l > mid) {
            return query(node * 2 + 1, mid + 1, end, l, r);
        }

        Node leftRes = query(node * 2, start, mid, l, r);
        Node rightRes = query(node * 2 + 1, mid + 1, end, l, r);
        return merge(leftRes, rightRes);
    }

public:
    SegmentTree(const vector<int>& nums, int k_val) : k(k_val) {
        n = nums.size();
        tree.resize(4 * n);
        build(nums, 1, 0, n - 1);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int l, int target_x) const {
        Node res = query(1, 0, n - 1, l, n - 1);
        return res.cnt[target_x];
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        // Optimize I/O operations
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        SegmentTree st(nums, k);
        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            st.update(q[0], q[1]);
            ans.push_back(st.query(q[2], q[3]));
        }

        return ans;
    }
};