class DSU{
    vector<int>parent,rank;
    public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;

        }
    }
        int find(int a)
        {
            if(parent[a]!=a)
            parent[a]=find(parent[a]);
            return parent[a];
        }
        void Unite(int a ,int b)
        {
            int x=find(a);
            int y=find(b);
            if(x==y)
            return ;
            else if(rank[x]>rank[y])
            {
                parent[y]=x;

            }
            else if(rank[x]<rank[y])
            {
                parent[x]=y;
            }
            else
            {
                parent[y]=x;
                rank[x]++;
            }
        }
    
};
class Solution {
public:

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DSU dsu(n);
        auto lambda=[&](vector<int>&v1,vector<int>&v2)
        {
            return v1[2]<v2[2];
        };
        for(int i=0;i<queries.size();i++)
        {
            queries[i].push_back(i);
        }
        vector<bool>ans(queries.size(),false);
        sort(edgeList.begin(),edgeList.end(),lambda);
        sort(queries.begin(),queries.end(),lambda);
        int j=0;
        for(auto l:queries)
        {
            int a=l[0];
            int b=l[1];
            int c=l[2];
            int d=l[3];
            for(int i=j;i<edgeList.size();i++)
            {
                if(edgeList[i][2]<c)
                {
                    dsu.Unite(edgeList[i][0],edgeList[i][1]);
                    j++;
                }
                else
                break;
            }
            if(dsu.find(a)==dsu.find(b))
            ans[d]=true;   
        }
        return ans;
    }
};