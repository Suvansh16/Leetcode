class Solution {
public:
vector<int>parent;
int find(int x)
{
    if(parent[x]==x)
    return x;
    return parent[x]=find(parent[x]);
}
void Union(int x,int y)
{
    parent[y]=x;
}
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        vector<int>cost(n);
        vector<int>result;
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            cost[i]=-1;
        }
        for(int i=0;i<edges.size();i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            int c=edges[i][2];
            int par_a=find(a);
            int par_b=find(b);
            if(par_a!=par_b)
            {
                 cost[par_a]&=cost[par_b];
                Union(par_a,par_b);
               
            }
            cost[par_a]&=c;
        }
        for(int i=0;i<query.size();i++)
        {
            int a=query[i][0];
            int b=query[i][1];
            int par_a=find(a);
            int par_b=find(b);
            if(a==b)
            result.push_back(0);
            else if(par_a!=par_b)
            {
                result.push_back(-1);
               
            }
            else
             result.push_back(cost[par_a]);
        }
        return result;
    }
};