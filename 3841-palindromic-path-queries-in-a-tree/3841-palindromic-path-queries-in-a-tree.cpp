class Solution {
public:
    vector<vector<int>> adj;
    vector<int> parent, depth, size, heavy, head, pos, seg;
    int timer = 0, N;

    int dfs(int u, int p) {
        parent[u] = p;
        size[u] = 1;
        int mx = 0;

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            int sub = dfs(v, u);
            size[u] += sub;

            if (sub > mx) {
                mx = sub;
                heavy[u] = v;
            }
        }

        return size[u];
    }

    void decompose(int u, int h, string& s, vector<int>& arr)
     {
        head[u] = h;
        pos[u] = timer;
        arr[timer++] = 1 << (s[u] - 'a');

        if (heavy[u] != -1)
            decompose(heavy[u], h, s, arr);

        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u])
                decompose(v, v, s, arr);
        }
    }

    void build(vector<int>& arr) 
    {
        N = 1;
        while (N < (int)arr.size()) N *= 2;

        seg.assign(2 * N, 0);

        for (int i = 0; i < (int)arr.size(); i++)
            seg[N + i] = arr[i];

        for (int i = N - 1; i > 0; i--)
            seg[i] = seg[2 * i] ^ seg[2 * i + 1];
    }

    void update(int p, int val) 
    {
        p += N;
        seg[p] = val;

        while (p > 1) {
            p /= 2;
            seg[p] = seg[2 * p] ^ seg[2 * p + 1];
        }
    }

    int query(int l, int r)
     {
        int ans = 0;
        l += N;
        r += N;

        while (l <= r) {
            if (l % 2 == 1)
             ans ^= seg[l++];
            if (r % 2 == 0)
             ans ^= seg[r--];

            l /= 2;
            r /= 2;
        }

        return ans;
    }

    int getPath(int u, int v) {
        int ans = 0;

        while (head[u] != head[v]) 
        {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            ans ^= query(pos[head[u]], pos[u]);
            u = parent[head[u]];
        }

        if (depth[u] > depth[v]) swap(u, v);

        ans ^= query(pos[u], pos[v]);

        return ans;
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        adj.resize(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        parent.resize(n);
        depth.assign(n, 0);
        size.resize(n);
        heavy.assign(n, -1);
        head.resize(n);
        pos.resize(n);

        dfs(0, -1);

        vector<int> arr(n);
        decompose(0, 0, s, arr);
        build(arr);

        vector<bool> ans;

        for (string& q : queries) {
            string type;
            int u, v;

            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                s[u] = c;
                update(pos[u], 1 << (c - 'a'));
            } else {
                ss >> v;

                int mask = getPath(u, v);
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};