class Solution {
public:
vector<int>parent;
vector<int>rank;
int find(int x)
{
    if(parent[x]==x)
    return x;
    return parent[x]=find(parent[x]);

}
void Union(int x,int y)
{
    int x_parent=find(x);
    int y_parent=find(y);
    if(x_parent==y_parent)
    {
        return ;
    }
    if(rank[x_parent]>rank[y_parent])
    {
        parent[y_parent]=x_parent;
    }
    else if(rank[y_parent]>rank[x_parent])
    {
         parent[x_parent]=y_parent;
    }
    else
    {
         parent[y_parent]=x_parent;
         rank[x_parent]++;
    }
}
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        int i=0;
        for (int i = 0; i < queries.size(); ++i) {
            queries[i].push_back(i);  // Append the original index to each query
        }
        //sort on the basis of threshold
        auto lambda=[&](vector<int>&v1,vector<int>&v2)
        {
            return v1[2]<v2[2];
        };
        sort(queries.begin(),queries.end(),lambda);
        sort(edgeList.begin(),edgeList.end(),lambda);
        int j=0;
        vector<bool>ans(queries.size(),false);
        for(auto l:queries)
        {
            int a=l[0];
            int b=l[1];
            int c=l[2];
            int d=l[3];
           for(int s=j;s<edgeList.size();s++)
           {
            if(edgeList[s][2]<c)
            {
                Union(edgeList[s][0],edgeList[s][1]);
                j++;
            }
            else
            break;
           }
           if(find(a)==find(b))
            ans[d]=true;
            
        }
        return ans;
    }
};