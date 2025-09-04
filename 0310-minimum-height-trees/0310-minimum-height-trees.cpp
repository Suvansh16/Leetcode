class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        vector<int>indegree(n,0);
        queue<int>q;
        if(n==1)
        return {0};
        unordered_map<int,vector<int>>map;
        for(auto i:edges)
        {
            indegree[i[0]]++;
            indegree[i[1]]++;
            map[i[0]].push_back(i[1]);
            map[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==1)
            q.push(i);
        }
        while(n>2)
        {
            n-=q.size();
            int size=q.size();
            while(size--)
            {
                int t=q.front();
                q.pop();
                for(int i:map[t])
                {
                    indegree[i]--;
                    if(indegree[i]==1)
                    q.push(i);
                }
            }
        }
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};