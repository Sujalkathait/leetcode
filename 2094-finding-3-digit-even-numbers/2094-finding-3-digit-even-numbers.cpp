class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int res[1000] = {0};
        vector<int> ans;

        for (int i = 0; i < digits.size(); i++) {
            for (int j = 0; j < digits.size(); j++) {
                for (int k = 0; k < digits.size(); k++) {

                    if (i == j || j == k || i == k)
                        continue;

                    if (digits[i] == 0)
                        continue;

                    if (digits[k] % 2 != 0)
                        continue;

                    res[digits[i] * 100 + digits[j] * 10 + digits[k]] = 1;
                }
            }
        }

        for (int n = 100; n < 1000; n++) {
            if (res[n]) {
                ans.push_back(n);
            }
        }

        return ans;
    }
};