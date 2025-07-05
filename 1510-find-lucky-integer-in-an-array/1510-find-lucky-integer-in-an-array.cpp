class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans=-1;
        unordered_map<int,int>map;
        for(int i:arr)
        map[i]++;
        for(auto i:map)
        {
            if(i.first==i.second)
            {
                ans=max(ans,i.first);
            }
        }
        return ans;

    }
};