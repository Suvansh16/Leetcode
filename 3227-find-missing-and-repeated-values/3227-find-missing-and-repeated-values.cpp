class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int>map;
        for(vector<int>&a:grid)
        {
            for(int i=0;i<a.size();i++)
            {
                map[a[i]]++;
            }
        }
        vector<int>ans;
        for(auto i:map)
        {
            if(i.second==2){
            ans.push_back(i.first);
            break;
            }
        }
        for(int i=1;i<=grid.size()*grid.size();i++)
        {
            if(map.find(i)==map.end())
            ans.push_back(i);
        }
        return ans;

    }
};