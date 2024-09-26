class Solution {
public:
int dp[51];
int solve(int i,unordered_set<string>&st,string s)
{
    if(i>=s.length())
    return 0;
    if(dp[i]!=-1)
    return dp[i];
    int res=1+solve(i+1,st,s);

    for(int j=i;j<s.length();j++)
    {
     string t=s.substr(i,j-i+1);
     if(st.count(t))
     {
        res=min(res,solve(j+1,st,s));
     }   
    }
    return dp[i]=res;
}
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string>st;
        memset(dp,-1,sizeof(dp));
        int n=dictionary.size();
        for(int i=0;i<n;i++)
        {
            st.insert(dictionary[i]);
        }
        return solve(0,st,s);
    }
};