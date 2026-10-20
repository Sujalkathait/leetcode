class Solution {
public:
    int sortableIntegers(vector<int>& nums)
     {
         int n = nums.size(), ans = 0;
        vector<int> div;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                div.push_back(i);

                if (i != n / i)
                    div.push_back(n / i);
            }
        }

        for (int k : div) {
            int last = -1;
            bool valid = true;

            for (int i = 0; i < n; i += k) {
                int mn = INT_MAX, mx = INT_MIN;
                int dip = 0;

                for (int j = i; j < i + k; j++) {
                    mn = min(mn, nums[j]);
                    mx = max(mx, nums[j]);

                    int next = nums[i + (j - i + 1) % k];

                    if (nums[j] > next)
                        dip++;
                }

                if (dip > 1 || last > mn) {
                    valid = false;
                    break;
                }

                last = mx;
            }

            if (valid)
                ans += k;
        }

        return ans;
    }
};