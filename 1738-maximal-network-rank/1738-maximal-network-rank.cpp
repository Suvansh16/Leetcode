class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,unordered_set<int>>map;
        for(auto i:roads)
        {
            map[i[0]].insert(i[1]);
            map[i[1]].insert(i[0]);

        }
        int maxans=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int size=map[i].size()+map[j].size();
                if(map[i].count(j))
                size-=1;
                maxans=max(maxans,size);
            }
        }
        return maxans;

    }
};