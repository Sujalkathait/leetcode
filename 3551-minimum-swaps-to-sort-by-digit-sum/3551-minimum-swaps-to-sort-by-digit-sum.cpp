
class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr = nums;

        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int x = digitSum(a);
            int y = digitSum(b);

            if (x == y) return a < b;
            return x < y;
        });

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
            mp[nums[i]] = i;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == arr[i])
                continue;

            int j = mp[arr[i]];

            swap(nums[i], nums[j]);

            mp[nums[j]] = j;
            mp[nums[i]] = i;

            ans++;
        }

        return ans;
    }
};
