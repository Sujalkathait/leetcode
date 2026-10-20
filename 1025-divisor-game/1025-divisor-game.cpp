class Solution {
public:
    bool divisorGame(int n) 
    {
           int even = 0, odd = 0;

        for (int i = 1; i <= n; i++)
         {
            if (i % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }

        return even >= odd;
    
    }
};