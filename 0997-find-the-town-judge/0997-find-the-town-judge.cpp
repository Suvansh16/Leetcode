class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>dp(n+1,0);
        for(auto i:trust){
            int a=i[0];
            int b=i[1];
            dp[b]++;
            dp[a]--;
        }
        for(int i=1;i<dp.size();i++)
        {
            if(dp[i]==n-1)
            return i;
        }
        return -1;
    }
};