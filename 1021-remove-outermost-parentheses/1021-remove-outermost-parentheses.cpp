class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int open = 0, close = 0;

        for (char ch : s)
         {
            if (ch == '(')
             {
                open++;

                // Keep only non-outermost '('
                if (open > 1)
                    ans += ch;
            }
            else {
                close++;

                // Keep only non-outermost ')'
                if (open > close)
                    ans += ch;

                // New primitive starts after open == close
                if (open == close) {
                    open = 0;
                    close = 0;
                }
            }
        }

        return ans;
    }
};