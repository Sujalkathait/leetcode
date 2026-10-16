class Solution {
public:
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0, sq = 0, lazy = 0;
    };

    vector<Node> t;

    void merge(int p) {
        t[p].sum = (t[p*2].sum + t[p*2+1].sum) % MOD;
        t[p].sq  = (t[p*2].sq + t[p*2+1].sq) % MOD;
    }

    void apply(int p, int l, int r, long long x) {
        long long len = r - l + 1;
        t[p].sq = (t[p].sq + 2*x*t[p].sum + x*x%MOD*len) % MOD;
        t[p].sum = (t[p].sum + x*len) % MOD;
        t[p].lazy += x;
    }

    void push(int p, int l, int r) {
        if (!t[p].lazy || l == r) return;

        int m = (l+r)/2;
        apply(p*2, l, m, t[p].lazy);
        apply(p*2+1, m+1, r, t[p].lazy);
        t[p].lazy = 0;
    }

    void update(int p, int l, int r, int L, int R) {
        if (r < L || R < l) return;

        if (L <= l && r <= R) {
            apply(p, l, r, 1);
            return;
        }

        push(p, l, r);
        int m = (l+r)/2;

        update(p*2, l, m, L, R);
        update(p*2+1, m+1, r, L, R);

        merge(p);
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        t.assign(4*n, Node());

        unordered_map<int,int> last;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = last.count(nums[i]) ? last[nums[i]] : -1;
            update(1, 0, n-1, prev+1, i);
            ans = (ans + t[1].sq) % MOD;
            last[nums[i]] = i;
        }

        return ans;
    }
};