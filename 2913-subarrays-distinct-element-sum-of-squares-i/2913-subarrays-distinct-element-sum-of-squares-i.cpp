class Solution {
public:
    int sumCounts(vector<int>& nums) 
    {
         int n=nums.size();
         int sum = 0;
         
        for (int i = 0; i < n; i++) {

            unordered_map<int, int> mp;

            for (int j = i; j < n; j++) {

                mp[nums[j]]++;

                int distinct = mp.size();

                sum += distinct * distinct;
            }
        }
        return sum;        
    }
};