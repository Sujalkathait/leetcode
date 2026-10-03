class Solution {
public:
    int longestValidParentheses(string s)
    {
        int n = s.length();
        int ans = 0;
        int open = 0, close = 0;

        // Left to right
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                open++;
            else
                close++;

            if (open == close)
            {
                if (2 * open > ans)
                    ans = 2 * open;
            }

            if (close > open)
                open = close = 0;
        }

        // Right to left
        open = close = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '(')
                open++;
            else
                close++;

            if (open == close)
            {
                if (2 * close > ans)
                    ans = 2 * close;
            }

            if (open > close)
                open = close = 0;
        }

        return ans;
    }
};