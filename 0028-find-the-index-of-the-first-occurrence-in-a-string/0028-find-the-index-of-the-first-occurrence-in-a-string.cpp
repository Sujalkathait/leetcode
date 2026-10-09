class Solution {
public:

     vector<int> buildLPS(string ptr) {
     int m = ptr.size();
    int len = 0;
    int i = 1;

    vector<int> lps(m, 0);

    while (i < m) {
        if (ptr[len] == ptr[i]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}
    int strStr(string haystack, string needle) 
    {
        int n=haystack.size();
        int m=needle.size();
        if (m == 0) 
        return 0; 
        vector<int> lps = buildLPS(needle);
        int i=0,j=0;
        while(i<n)
        {
        if(haystack[i]==needle[j])
        {
            i++;
            j++;
        }
        if (j == m) 
        { 
            return i - j; 
            }
            else if (i < n && haystack[i] != needle[j]) 
            { 
                if (j != 0) 
                { 
                    j = lps[j - 1]; 
                    } 
                    else 
                    {
                         i++;
                     }                  
         } 
        }
                return -1;
    }
                           
};