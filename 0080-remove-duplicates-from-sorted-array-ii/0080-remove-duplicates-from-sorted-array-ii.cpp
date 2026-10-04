class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int k = 0;

    for (int i = 0; i < nums.size(); )
    {
        int count = 1;

        while (i + count < nums.size() && nums[i] == nums[i + count])
            count++;

        nums[k++] = nums[i];

        if (count >= 2)
            nums[k++] = nums[i];

        i += count;
    }

    return k;
   

    }
};