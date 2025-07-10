class DSU{

    public:
    unordered_map<int,int>parent;
    int find(int x)
    {
        if(!parent.count(x))
        parent[x]=x;
        if(parent[x]!=x)
        parent[x]=find(parent[x]);
        return parent[x];
    }
    void unite(int a,int b)
    {
        int px=find(a);
        int py=find(b);
        if(px!=py)
        parent[px]=py;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu;
        unordered_map<int,vector<int>>map;
        for(int i=0;i<stones.size();i++)
        {
            for(int j=i+1;j<stones.size();j++)
            {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                {map[i].push_back(j);
                map[j].push_back(i);}

            }
        }
        for(auto i:map)
        {
            int a=i.first;
            for(int j:i.second)
            {
                dsu.unite(a,j);
            }
        }
        unordered_set<int> uniqueRoots;
        for (int i = 0; i < stones.size(); ++i) {
            uniqueRoots.insert(dsu.find(i));
        }

        // Max removable stones = total - number of components
        return stones.size() - uniqueRoots.size();
    }
};