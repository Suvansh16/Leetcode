class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1,0);
        dp[0]=0;
        for(int i=1;i<=days.size();i++)
        {
            int cost1=costs[0]+dp[i-1];
            int l=days[i-1];
            int idx=i-1;

            while(idx>=0 && days[idx]>(l-7))
            {
                idx--;
            }

            int cost2=costs[1]+dp[idx+1];
            idx=i-1;
             while(idx>=0 && days[idx]>(l-30))
            {
                idx--;
            }
            int cost3=dp[idx+1]+costs[2];
            dp[i]=min({cost1,cost2,cost3});



        }
        return dp[days.size()];
    }
};