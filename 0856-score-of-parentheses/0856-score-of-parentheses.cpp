class Solution {
public:
    int scoreOfParentheses(string s) 
    {
        stack<int> scores;
        scores.push(0);

        for (char x : s) {
            if (x == '(') {
                scores.push(0);
            } 
            else {
                int tempScore = scores.top();
                scores.pop();

                int currentScore;

                if (tempScore == 0) {
                    currentScore = 1;
                } 
                else {
                    currentScore = 2 * tempScore;
                }

                scores.top() += currentScore;
            }
        }

        return scores.top();
    }
};