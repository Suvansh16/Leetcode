class DSU{
    vector<int>parent,rank;
    public:
    DSU(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++)
        parent[i]=i;

    }
    int find(int a)
    {
        if(parent[a]!=a)
        parent[a]=find(parent[a]);
        return parent[a];
    }
    void Unite(int a,int b)
    {
        int x=find(a);
        int y=find(b);
        if(x==y)
        return ;
        else if(rank[x]>rank[y])
        parent[y]=x;
        else if(rank[x]<rank[y])
        parent[x]=y;
        else
        {
            parent[y]=x;
            rank[x]++;
        }
    }
    vector<int>get_par(){
    return parent;
    }


};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int count=0;
        auto lambda=[&](vector<int>&v1,vector<int>&v2)
        {
            return v1[0]>v2[0];
        };
        DSU dsu1(n);
        DSU dsu2(n);
        sort(edges.begin(),edges.end(),lambda);
        for(auto i:edges)
        {
            int a=i[0];
            int b=i[1];
            int c=i[2];
            if(a==3)
            {
                int m=dsu1.find(b);
                int n=dsu1.find(c);                
                if(m!=n)
                dsu1.Unite(b,c);
                int o=dsu2.find(b);
                int p=dsu2.find(c);
                if(o!=p)
                dsu2.Unite(b,c);
                if(m==n && o==p)
                count++;

            }
            else if(a==1){
                 int m=dsu1.find(b);
                int n=dsu1.find(c);                
                if(m!=n)
                dsu1.Unite(b,c);
                 else 
                count++;
            }
            else if(a==2)
            {
                  int o=dsu2.find(b);
                int p=dsu2.find(c);
                if(o!=p)
                dsu2.Unite(b,c);
                else
                count++;
            }

        }
        vector<int>v1=dsu1.get_par();
        vector<int>v2=dsu2.get_par();
        unordered_set<int>st1;
        unordered_set<int>st2;
        for(int i=1;i<=n;i++)
        {
            st1.insert(dsu1.find(i));
            st2.insert(dsu2.find(i));
        }
        if(st1.size()>1 || st2.size()>1)
        return -1;
        return count;
    }
};