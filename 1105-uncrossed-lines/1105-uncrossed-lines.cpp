class Solution {
public:
int n,m;
int dp[501][501];
int solve(int i,int j,vector<int>& nums1, vector<int>& nums2)
{
    if(i>=n || j>=m)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int equal=0;
    int notequal=0;
    if(nums1[i]==nums2[j])
    {
        equal=1+solve(i+1,j+1,nums1,nums2);
    }
    else
    {
        int a=solve(i+1,j,nums1,nums2);
        int b=solve(i,j+1,nums1,nums2);
        notequal=max(a,b);
    }
    return dp[i][j]=max(equal,notequal);

}
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        m=nums2.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,nums1,nums2);
    }
};