class Solution {
public:
    bool isCircularSentence(string s) {
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                if(i-1<0)
                return false;
                else if(s[i-1]==' ')
                return false;
                else if(i+1>=n)
                return false;
                else if(s[i-1]!=s[i+1])
                return false;
            }
        }
        if(s[0]!=s[n-1])
        return false;
        return true;
    }
};