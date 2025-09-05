class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans=0;
        vector<int>indegree(n,0);
        for(auto i:roads)
        {
            indegree[i[0]]++;
            indegree[i[1]]++;
        }
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        v.push_back({indegree[i],i});
        sort(v.begin(),v.end());
        unordered_map<int,int>map;
        int k=n;
        for(int i=n-1;i>=0;i--)
        map[v[i].second]=k--;
        for(auto i:roads)
        {
            ans+=map[i[0]];
            ans+=map[i[1]];
        }
        return ans;
    }
};