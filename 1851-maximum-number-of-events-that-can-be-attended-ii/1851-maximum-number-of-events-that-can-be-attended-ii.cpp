class Solution {
public:
int solve(int start,vector<vector<int>>&events,int k,vector<vector<int>>&dp){
if(k<=0)
return 0;
if(start>=events.size())
return 0;
if(dp[start][k]!=-1)
return dp[start][k];
//find the next event which we can attend
int j=start+1;
for(;j<events.size();j++)
{
    if(events[j][0]>events[start][1])
    {
        break;
    }
}

int doing=events[start][2]+solve(j,events,k-1,dp);
int notdo=solve(start+1,events,k,dp);
return dp[start][k]=max(doing,notdo);
}
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        vector<vector<int>>dp(events.size()+1,vector<int>(k+1,-1));
        return solve(0,events,k,dp);
    }
};