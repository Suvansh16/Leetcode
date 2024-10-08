class Solution {
public:
vector<int>parent;
vector<int>rank;
int find(int x)
{
    if(x==parent[x])
    return x;
    return parent[x]=find(parent[x]);
}
void Union(int x,int y)
{
    int root_x=find(x);
    int root_y=find(y);
    if(root_x==root_y)
    return;
    if(rank[root_x]>rank[root_y])
    {
        parent[root_y]=parent[root_x];
    }
    else if(rank[root_y]>rank[root_x])
    {
        parent[root_x]=parent[root_y];
    }
    else
    {
        parent[root_y]=parent[root_x];
        rank[root_x]++;
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<n;i++)
        {
           for(int j=0;j<n;j++)
           {
            if(isConnected[i][j]==1 && find(i)!=find(j))
            Union(i,j);
           }
        }
        unordered_set<int>temp;
        for(int i=0;i<n;i++)
        {
            temp.insert(find(i));
        }
        return temp.size();
    }
};