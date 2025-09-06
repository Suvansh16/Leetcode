class Solution {
public:
void solve(int start,unordered_map<int,vector<int>>&map,vector<int>&output,unordered_set<int>&st)
{
    if(map[start].empty())
    return ;
    for(int i=0;i<map[start].size();i++)
    {
        if(st.find(map[start][i])==st.end())
        {
            st.insert(map[start][i]);
            solve(map[start][i],map,output,st);
            output.push_back(map[start][i]);

        }
    }
    return ;
}

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>ans;
        unordered_map<int,vector<int>>map;
        for(auto i:edges)
        {
            map[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++)
        {
            vector<int>t,output;
            unordered_set<int>st;
            solve(i,map,output,st);
            t=output;
            sort(t.begin(),t.end());
            ans.push_back(t);
        }
        return ans;
    }
};