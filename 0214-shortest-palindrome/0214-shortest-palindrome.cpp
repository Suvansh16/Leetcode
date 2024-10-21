class Solution {
public:
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        int n=s.length();
        for(int i=0;i<s.length();i++)
        {
            
            if(memcmp(s.c_str(),rev.c_str()+i,n-i)==0)
            {
                return rev.substr(0,i)+s;
            }
        }
        return rev+s;
    }
};