
class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<long long>> dp;

    int solve(vector<int>& nums)
    {
        int n = nums.size();

        if (n <= 2)
            return 1;

        vector<int> left, right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long a = solve(left) % MOD;
        long long b = solve(right) % MOD;
        long long c = dp[n - 1][left.size()];

        return (((a * b) % MOD) * c) % MOD;
    }

    int numOfWays(vector<int>& nums)
    {
        int n = nums.size();

        dp.resize(n + 1);

        // Populating Pascal's Triangle
        for (int i = 0; i <= n; i++) {

            dp[i] = vector<long long>(i + 1, 1);

            for (int j = 1; j < i; j++) {

                dp[i][j] = (dp[i - 1][j - 1] +
                            dp[i - 1][j]) % MOD;
            }
        }

        return (solve(nums) - 1 + MOD) % MOD;
    }
};
