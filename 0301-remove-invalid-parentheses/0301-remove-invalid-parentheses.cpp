class Solution {
public:
    unordered_set<string> ans;

    void dfs(string &s, int idx, int balance,
             int lremove, int rremove, string path) {

        if (idx == s.size()) {
            if (balance == 0 &&
                lremove == 0 &&
                rremove == 0) {
                ans.insert(path);
            }
            return;
        }

        char ch = s[idx];

        // Remove '('
        if (ch == '(' && lremove > 0) {
            dfs(s, idx + 1, balance,
                lremove - 1, rremove, path);
        }

        // Remove ')'
        if (ch == ')' && rremove > 0) {
            dfs(s, idx + 1, balance,
                lremove, rremove - 1, path);
        }

        // Keep current character
        if (ch != '(' && ch != ')') {
            dfs(s, idx + 1, balance,
                lremove, rremove, path + ch);
        }
        else if (ch == '(') {
            dfs(s, idx + 1, balance + 1,
                lremove, rremove, path + ch);
        }
        else if (ch == ')' && balance > 0) {
            dfs(s, idx + 1, balance - 1,
                lremove, rremove, path + ch);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int lremove = 0;
        int rremove = 0;

        // Calculate minimum removals
        for (char ch : s) {

            if (ch == '(') {
                lremove++;
            }
            else if (ch == ')') {

                if (lremove > 0) {
                    lremove--;
                }
                else {
                    rremove++;
                }
            }
        }

        dfs(s, 0, 0, lremove, rremove, "");

        return vector<string>(ans.begin(), ans.end());
    }
};