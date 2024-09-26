class Solution {
public:

    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int>dp(s.length()+1,0);
        int n=s.length();
        unordered_set<string>st;
        for(int i=0;i<dictionary.size();i++)
        st.insert(dictionary[i]);
        for(int i=n-1;i>=0;i--)
        {
            dp[i]=1+dp[i+1];
            for(int j=i;j<n;j++)
            {
                string curr=s.substr(i,j-i+1);
                if(st.count(curr))
                {
                    dp[i]=min(dp[i],dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};