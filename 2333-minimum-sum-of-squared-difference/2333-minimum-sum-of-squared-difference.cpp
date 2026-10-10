class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        vector<long long> diff(n);
        long long mx = 0;
        long long operations = (long long)k1 + k2;

        for (int i = 0; i < n; i++) {
            diff[i] = abs((long long)nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
        }

        long long low = 0, high = mx;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long needed = 0;

            for (long long d : diff) {
                if (d > mid) {
                    needed += d - mid;
                    if (needed > operations)
                        break;
                }
            }

            if (needed <= operations)
                high = mid;
            else
                low = mid + 1;
        }

        long long target = low;
        long long remaining = operations;

        for (int i = 0; i < n; i++) {
            if (diff[i] > target) {
                remaining -= diff[i] - target;
                diff[i] = target;
            }
        }

        for (int i = 0; i < n && remaining > 0; i++) {
            if (diff[i] == target && target > 0) {
                diff[i]--;
                remaining--;
            }
        }

        long long ans = 0;

        for (long long d : diff) {
            ans += d * d;
        }

        return ans;
    }
};