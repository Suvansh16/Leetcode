class Solution {
public:
bool bfs(unordered_map<int,vector<int>>&map,int curr,int currcolor,vector<int>&color)
{
    queue<int>q;
    q.push(curr);
    color[curr]=currcolor;
   while(!q.empty())
   {
    int a=q.front();
    q.pop();
    for(auto &i:map[a])
    {
        if(color[i]==color[a])
        {
            return false;
        }
        if(color[i]==-1)
        {
            q.push(i);
            currcolor=1-color[a];
              color[i]=currcolor;
        }
    }
   }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        unordered_map<int,vector<int>>map;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                map[i].push_back(graph[i][j]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(bfs(map,i,1,color)==false)
                return false;
            }
        }
        return true;
    }
};