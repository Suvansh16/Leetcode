class Solution {
public:
int dp[101][101];
int count_steps(int ring_index,int i,string ring)
{
    int a=abs(i-ring_index);
    int b=ring.length()-a;
    return min(a,b);
}
int solve(int ring_index,int key_index,string ring,string key)
{
    if(key_index==key.size())
    return 0;
    if(dp[ring_index][key_index]!=-1)
    return dp[ring_index][key_index];
    int ans=INT_MAX;
    for(int i=0;i<ring.size();i++)
    {
        if(ring[i]==key[key_index])
        {
            int steps=count_steps(ring_index,i,ring);
            int total_steps=steps+1+solve(i,key_index+1,ring,key);
            ans=min(ans,total_steps);
        }
    }
    return dp[ring_index][key_index]=ans;
}
    int findRotateSteps(string ring, string key) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,ring,key);
    }
};