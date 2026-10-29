#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos;
    vector<int> subtree_size;
    int cur_pos;

    // Segment Tree arrays
    vector<int> tree;
    string s_nodes;

    void dfs_sz(int v, int p, int d) {
        subtree_size[v] = 1;
        depth[v] = d;
        parent[v] = p;
        int max_sz = 0;
        for (int u : adj[v]) {
            if (u != p) {
                dfs_sz(u, v, d + 1);
                subtree_size[v] += subtree_size[u];
                if (subtree_size[u] > max_sz) {
                    max_sz = subtree_size[u];
                    heavy[v] = u;
                }
            }
        }
    }

    void dfs_hld(int v, int h) {
        head[v] = h;
        pos[v] = cur_pos++;
        if (heavy[v] != -1) {
            dfs_hld(heavy[v], h);
        }
        for (int u : adj[v]) {
            if (u != parent[v] && u != heavy[v]) {
                dfs_hld(u, u);
            }
        }
    }

    void build_tree(int node, int start, int end) {
        if (start == end) {
            tree[node] = (1 << (s_nodes[start] - 'a'));
            return;
        }
        int mid = (start + end) / 2;
        build_tree(2 * node, start, mid);
        build_tree(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    void update_tree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid)
            update_tree(2 * node, start, mid, idx, val);
        else
            update_tree(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    int query_tree(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return 0;
        if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        return query_tree(2 * node, start, mid, l, r) ^ query_tree(2 * node + 1, mid + 1, end, l, r);
    }

    int query_path(int u, int v) {
        int res = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                swap(u, v);
            }
            res ^= query_tree(1, 0, n - 1, pos[head[v]], pos[v]);
            v = parent[head[v]];
        }
        if (depth[u] > depth[v]) {
            swap(u, v);
        }
        res ^= query_tree(1, 0, n - 1, pos[u], pos[v]);
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        subtree_size.assign(n, 0);
        cur_pos = 0;

        dfs_sz(0, -1, 0);
        dfs_hld(0, 0);

        s_nodes.resize(n);
        for (int i = 0; i < n; ++i) {
            s_nodes[pos[i]] = s[i];
        }

        tree.assign(4 * n, 0);
        build_tree(1, 0, n - 1);

        vector<bool> answer;
        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                s[u] = c;
                update_tree(1, 0, n - 1, pos[u], (1 << (c - 'a')));
            } else {
                int u, v;
                ss >> u >> v;
                int mask = query_path(u, v);
                // Check if at most one bit is set
                bool is_palindrome = (mask & (mask - 1)) == 0;
                answer.push_back(is_palindrome);
            }
        }

        return answer;
    }
};