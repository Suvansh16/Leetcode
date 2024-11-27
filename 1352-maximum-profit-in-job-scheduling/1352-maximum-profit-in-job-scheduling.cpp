class Solution {
public:
int n;
int memo[50001];
int next(vector<vector<int>>&temp,int ind,int currend)
{
    int result=n+1;
    int l=ind,r=n-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(temp[mid][0]>=currend)
        {
            result=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }

    return result;
}
int solve(vector<vector<int>>&temp,int start)
{
    if(start>=n)
    return 0;
    if(memo[start]!=-1)
    return memo[start];
    int nextjob=next(temp,start+1,temp[start][1]);
    int take=temp[start][2]+solve(temp,nextjob);
    int nottake=solve(temp,start+1);
    return memo[start]=max(take,nottake);
}
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        vector<vector<int>>temp(n,vector<int>(3,0));
        for(int i=0;i<n;i++)
        {
            temp[i][0]=startTime[i];
            temp[i][1]=endTime[i];
            temp[i][2]=profit[i];
        }
        auto lambda=[&](vector<int>&v1,vector<int>&v2)
        {
            return v1[0]<v2[0];
        };
        sort(temp.begin(),temp.end(),lambda);
        memset(memo,-1,sizeof(memo));
        return solve(temp,0);
    }
};