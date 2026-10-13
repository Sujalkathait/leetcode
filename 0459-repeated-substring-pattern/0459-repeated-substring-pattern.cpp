class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
        int n=s.size();
        vector<int>lps(n,0);
        int len=0;
        int i=1;
        while(i<n)
        {
             if (s[i] == s[len])
             {
            len++;
            lps[i]=len;
            i++;
             }
             else
             {
                if(len!=0)
                {
                    len=lps[len-1];
                }
                else
                {
                    i++;
                }
             }
        }
        int x=lps[n-1];
        int y=n-x;
        if(x>0 && n%y==0)
        {
            return true;
        }
        return false;

    }
};