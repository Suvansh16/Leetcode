class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int,vector<int>>map;
         vector<int>indegree(n,0);
        for(int i=0;i<relations.size();i++)
        {
            int u=relations[i][0]-1;
            int v=relations[i][1]-1;
            map[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        vector<int>maxtime(n,0);
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                maxtime[i]=time[i];
            }
        }
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            for(int &v:map[a])
            {
                indegree[v]--;
                maxtime[v]=max(maxtime[v],time[v]+maxtime[a]);
                if(indegree[v]==0)
                q.push(v);
            }
        }
       return *max_element(maxtime.begin(),maxtime.end());

    }
};