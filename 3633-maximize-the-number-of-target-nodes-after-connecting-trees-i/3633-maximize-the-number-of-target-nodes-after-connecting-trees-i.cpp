class Solution {
public:
int dfs(int start,int par,unordered_map<int,vector<int>>&map,int val)
{
    if(val<=0)
    return 0;
    int ans=0;
    for(int i:map[start])
    {
        if(i!=par)
        ans+=1+dfs(i,start,map,val-1);
    }
    return ans;

}
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        unordered_map<int,vector<int>>map1,map2;
        for(auto i:edges1)
        {
            map1[i[0]].push_back(i[1]);
            map1[i[1]].push_back(i[0]);
        }
        for(auto i:edges2)
        {
            map2[i[0]].push_back(i[1]);
            map2[i[1]].push_back(i[0]);
        }
        int n=edges1.size(),m=edges2.size();
        vector<int>ans;
        vector<int>t(m+1,0);
        for(int j=0;j<=m;j++)
        {
            int l=dfs(j,-1,map2,k-1);
            t[j]=l+1;
        }
        int s=*max_element(t.begin(),t.end());

        for(int i=0;i<=n;i++)
        {
            int a=dfs(i,-1,map1,k);
            if(k!=0)
            ans.push_back(a+s+1);
            else
            ans.push_back(1);
        }
        return ans;

    }
};