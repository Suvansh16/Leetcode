class Solution {
public:
vector<int>parent;
vector<int>rank;
int find(int i)
{
    if(i==parent[i])
    return i;
   return  parent[i]=find(parent[i]);
}
void Union(int x,int y)
{
    int x_parent=find(x);
    int y_parent=find(y);
    if(x_parent!=y_parent)
    {
        if(rank[x_parent]>rank[y_parent])
        {
            parent[y_parent]=x_parent;
        
        }
        else if(rank[x_parent]<rank[y_parent])
        {
            parent[x_parent]=y_parent;
        }
        else
        {
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
}
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        for(vector<int>&v:edges)
        {
           Union(v[0],v[1]);

        }
        map<int,int>map;
        for(int i=0;i<n;i++)
        {
            int a=find(i);
            map[a]++;
        }
        vector<int>values;
        for(auto a:map)
        {
            values.push_back(a.second);
        }
        if(values.size()==1)
        return 0;
        long long ans=0;
        int k=values.size();
        // for(int i=0;i<k;i++)
        // {
        //     for(int j=i+1;j<k;j++)
        //     {
        //         ans+=values[i]*values[j];
        //     }
        // }
        //double loop will give run time error
        int size=n;
        long long  total=0;
        for(auto i:map)
        {
            long long  a=i.second;
            ans+=(size-total-a)*a;
            total+=i.second;

        }
        return ans;
    }
};