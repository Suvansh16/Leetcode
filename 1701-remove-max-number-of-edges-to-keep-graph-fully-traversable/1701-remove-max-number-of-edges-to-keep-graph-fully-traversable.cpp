class DSU{
    private:
    int components;
    vector<int>parent;
    vector<int>rank;

    public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        components=n;
        for(int i=1;i<=n;i++)
        parent[i]=i;
    }
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
        return;
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
        components--;
    }
    bool issingle()
    {
        return components==1;
    }
};
class Solution {
public:

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        auto lambda=[&](vector<int>&v1,vector<int>&v2)
        {
            return v1[0]>v2[0];
        };
        sort(edges.begin(),edges.end(),lambda);
        DSU alice(n);
        DSU bob(n);

        int addedge=0;
        for(auto &edge:edges)
        {
            int type=edge[0];
            int u=edge[1];
            int v=edge[2];
            if(type==3)
            {
                bool add=false;
                if(alice.find(u)!=alice.find(v))
                {
                    alice.Union(u,v);
                    add=true;
                }
                if(bob.find(u)!=bob.find(v))
                {
                    bob.Union(u,v);
                    add=true;
                }
                if(add)
                addedge++;
            }
            else if(type==2)
            {
                if(bob.find(u)!=bob.find(v))
                {
                    bob.Union(u,v);
                    addedge++;
                }
            }
            else
            {
                if(alice.find(u)!=alice.find(v))
                {
                    alice.Union(u,v);
                    addedge++;

                }
            }
        }
        if(alice.issingle() && bob.issingle())
        {
            return edges.size()-addedge;

        }
        return -1;


    }
};