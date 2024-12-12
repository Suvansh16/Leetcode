class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        vector<vector<int>>t(s.length(),vector<int>(s.length(),0));
        for(int l=2;l<=n;l++)
        {
            for(int i=0;i<n-l+1;i++)
            {
                int j=i+l-1;
                if(s[i]==s[j])
                t[i][j]=t[i+1][j-1];
                else
                t[i][j]=1+min(t[i][j-1],t[i+1][j]);
            }
        }
        return t[0][n-1];
    }
};