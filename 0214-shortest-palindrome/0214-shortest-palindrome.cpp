class Solution {
public:
    string shortestPalindrome(string s) 
    {
         string rev = s;
        reverse(rev.begin(), rev.end());

        string combined = s + "#" + rev;
        vector<int> lps(combined.size(), 0);

        int len = 0;

        for (int i = 1; i < combined.size();) {
            if (combined[i] == combined[len]) {
                lps[i] = ++len;
                i++;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }

        int palLen = lps.back();
        string add = rev.substr(0, s.size() - palLen);

        return add + s;
    }
};