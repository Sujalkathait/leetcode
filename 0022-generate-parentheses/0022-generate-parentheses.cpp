class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;

        function<void(string)> generate = [&](string s) {

            if (s.length() == 2 * n) {

                int count = 0;

                for (char c : s) {
                    if (c == '(')
                        count++;
                    else
                        count--;

                    if (count < 0)
                        return;
                }

                if (count == 0)
                    ans.push_back(s);

                return;
            }

            generate(s + '(');
            generate(s + ')');
        };

        generate("");

        return ans;
    }
};