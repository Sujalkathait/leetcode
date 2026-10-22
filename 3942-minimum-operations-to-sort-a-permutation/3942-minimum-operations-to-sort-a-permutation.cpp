class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
         int n = nums.size();
        int ascorder = 0, descorder = 0;

        for (int i = 1; i < n; i++)
         {
            if (nums[i] == (nums[i - 1] + 1) % n)
                ascorder++;

            if (nums[i - 1] == (nums[i] + 1) % n)
                descorder++;
        }

        if (ascorder == n - 1 && nums[0] == 0)
            return 0;

        if (ascorder == n - 1)
         {
            int leftRot = (n - nums[0]) % n;
            int rightRot = nums[0] + 2;
            return min(leftRot, rightRot);
        }

        if (descorder == n - 1)
         {
            int reverseFirst = n - nums[0];
            int rotateFirst = (nums[0] + 1) % n + 1;
            return min(reverseFirst, rotateFirst);
        }

        return -1;
    }
};