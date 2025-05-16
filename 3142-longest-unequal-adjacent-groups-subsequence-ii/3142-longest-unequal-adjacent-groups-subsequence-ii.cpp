class Solution {
public:
bool checkHammingDistance(string &a1,string &a2)
{
    int diff=0;
    for(int i=0;i<a1.length();i++)
    {
        if(a1[i]!=a2[i])
        diff++;
        if(diff>1)
        return false;
    }
    return diff==1;
}
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<int>dp(n,1);
        int LIS=1;
        vector<int>parent(n,-1);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i-1;j++)
            {
                if(groups[i]!=groups[j] && words[i].length()==words[j].length() && 
                checkHammingDistance(words[i],words[j]))
                {
                    if(dp[j]+1>dp[i])
                    {
                        dp[i]=dp[j]+1;
                        LIS=max(LIS,dp[i]);
                        parent[i]=j;


                    }
                }
            }
        }

        int idx=-1;
       for(int i=0;i<n;i++)
        {
            if(dp[i]==LIS)
            idx=i;
        }
        vector<string>result;
        while(idx!=-1)
        {
            result.push_back(words[idx]);
            idx=parent[idx];
        }
        reverse(result.begin(),result.end());
        return result;
    }
};