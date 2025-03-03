class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>map;
        for(int i=0;i<edges.size();i++)
        {
            map[edges[i][0]].push_back(edges[i][1]);
            map[edges[i][1]].push_back(edges[i][0]);
        }
        int ans;
        for(auto i:map)
        {
            if(i.second.size()>1)
            {
                ans=i.first;
            }
        }
        return ans;
    }
};