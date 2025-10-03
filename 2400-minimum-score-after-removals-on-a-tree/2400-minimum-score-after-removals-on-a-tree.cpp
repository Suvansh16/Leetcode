class Solution {
public:
int getscore(int a,int b,int c)
{
    int maxi=max({a,b,c});
    int mini=min({a,b,c});
    return maxi-mini;
}
bool isancestor(int a,int b,vector<int>&intime,vector<int>&outtime)
{
    return intime[b]>=intime[a] && outtime[a]>=outtime[b];

}
void dfs(int node,int par,vector<int>&subtree,vector<int>&intime,vector<int>&outtime,int &timer,vector<int>&nums,unordered_map<int,vector<int>>&map)
{
    subtree[node]=nums[node];
    intime[node]=timer;
    timer++;
    for(int &n:map[node])
    {
        if(n!=par)
        {
            dfs(n,node,subtree,intime,outtime,timer,nums,map);
            subtree[node]^=subtree[n];
        }
    }
    outtime[node]=timer;
    timer++;
}
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int timer=0;
        int n=nums.size();
        unordered_map<int,vector<int>>map;
        for(auto i:edges)
        {
            map[i[0]].push_back(i[1]);
            map[i[1]].push_back(i[0]);
        }
        vector<int>intime(n,0);
        vector<int>outtime(n,0);
        vector<int>subtree(n,0);
        dfs(0,-1,subtree,intime,outtime,timer,nums,map);
        int result=INT_MAX;
        for(int u=1;u<n;u++)
        {
            for(int v=u+1;v<n;v++)
            {
                int xor1,xor2,xor3;
                if(isancestor(u,v,intime,outtime))
                {
                    xor1=subtree[u];
                    xor2=subtree[v];
                    xor1=xor1^xor2;
                    xor3=subtree[0]^xor1^xor2;
                }
                else if(isancestor(v,u,intime,outtime))
                {
                    xor1=subtree[v];
                    xor2=subtree[u];
                    xor1=xor1^xor2;
                    xor3=subtree[0]^xor1^xor2;
                }
                else
                {
                    xor1=subtree[u];
                    xor2=subtree[v];
                    xor3=xor1^xor2^subtree[0];
                }
                result=min(result,getscore(xor1,xor2,xor3));
            }
            

        }
        return result;
    }
};