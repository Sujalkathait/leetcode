class Solution {
public:
    int minInsertions(string s)
     {
        int open = 0;
        int close = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            open++;  // Count opening brackets
        }
        else {
            // Check if the next character is also ')'
            if (i< s.size() && s[i+1 ] == ')') {
                if (open > 0) {
                    open--;  // Match one opening bracket
                }
                else {
                    close++;  // Insert missing '('
                }

                i++;  // Skip the second ')'
            }
            else {
                close++;  // Insert missing ')' to make '))'

                if (open > 0) {
                    open--;  // Match one opening bracket
                }
                else {
                    close++;  // Insert missing '('
                }
            }
        }
    }

    close += open * 2;  // Each unmatched '(' needs two ')'

    return close;
     }
};