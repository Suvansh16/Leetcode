class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int,vector<int>>map;
         vector<int>indegree(n,0);
        for(auto i:relations)
        {
            indegree[i[1]-1]++;
            map[i[0]-1].push_back(i[1]-1);
        }
        queue<int>q;
        vector<int>maxtime(n,0);
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                maxtime[i]=time[i];
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            for(int i:map[a])
            {
                indegree[i]--;
                maxtime[i]=max(maxtime[i],time[i]+maxtime[a]);
                if(indegree[i]==0)
                q.push(i);
            }
        }
         return *max_element(maxtime.begin(),maxtime.end());
       
        

    }
};