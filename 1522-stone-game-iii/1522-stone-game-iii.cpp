class Solution {
public:
int n;
int dp[50001];
int solve(int i,vector<int>&v){
    if(i>=n)
    return 0;
    if(dp[i]!=-1)
    return dp[i];
    int result=INT_MIN;
    result=max(result,v[i]-solve(i+1,v));
    if(i+1<n)
    result=max(result,v[i]+v[i+1]-solve(i+2,v));
    if(i+2<n)
    result=max(result,v[i]+v[i+1] +v[i+2]-solve(i+3,v));
    return dp[i]=result;
}
    string stoneGameIII(vector<int>& stoneValue) {
         memset(dp,-1,sizeof(dp));
         n=stoneValue.size();
        int val=solve(0,stoneValue);
        if(val>0)
        return "Alice";
        if(val<0)
        return "Bob";
        return "Tie";
    }
};