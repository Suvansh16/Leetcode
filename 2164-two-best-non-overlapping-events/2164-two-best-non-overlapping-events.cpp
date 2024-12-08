class Solution {
public:
int binary(vector<vector<int>>& events,int a)
{
    int l=1;
    int r=events.size()-1;
    int ans=r+1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(events[mid][0]>a)
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return ans;

}
int solve(vector<vector<int>>& events,int start,int count,vector<vector<int>>&dp)
{
    if(start>=events.size() || count==2)
    {
        return 0;

    }
    if(dp[start][count]!=-1)
    {
        return dp[start][count];
    }
    int nextvalidindex=binary(events,events[start][1]);
    int take=events[start][2]+solve(events,nextvalidindex,count+1,dp);
    int nottake=solve(events,start+1,count,dp);
    return dp[start][count]=max(take,nottake);
}
    int maxTwoEvents(vector<vector<int>>& events) {
       sort(events.begin(),events.end());
       vector<vector<int>>dp(events.size(),vector<int>(2,-1));
       return solve(events,0,0,dp);
    }
};