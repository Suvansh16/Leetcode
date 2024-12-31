class Solution {
public:
int solve(int start,vector<int>&days,vector<int>&costs,vector<int>&dp)
{
    if(start>=days.size())
    return 0;
    if(dp[start]!=-1)
    return dp[start];
    int a=costs[0]+solve(start+1,days,costs,dp);
    int m=start;
    int s=days[m]+7;
    while( m<days.size() && s>days[m])
    m++;
    int b=costs[1]+solve(m,days,costs,dp);
     int n=start;
    int p=days[n]+30;
    while( n<days.size() && p>days[n])
    n++;
    int c=costs[2]+solve(n,days,costs,dp);


    return dp[start]=min({a,b,c});
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(366,-1);
        return solve(0,days,costs,dp);
    }
};