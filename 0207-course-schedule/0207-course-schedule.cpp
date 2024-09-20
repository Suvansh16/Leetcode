class Solution {
public:
bool dfs(int i,vector<bool>&visited,vector<bool>&dfsvisit,unordered_map<int,vector<int>>&map)
{
    visited[i]=true;
    dfsvisit[i]=true;
    for(auto neighbour:map[i])
    {
        if(!visited[neighbour])
        {
            bool cycledetect=dfs(neighbour,visited,dfsvisit,map);
            if(cycledetect==true)
            return true;

        }
        else if(dfsvisit[neighbour])
        return true;
    }
    dfsvisit[i]=false;
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        unordered_map<int,vector<int>>map;
        for(int i=0;i<prerequisites.size();i++)
        {
            map[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        int n=numCourses;
        vector<bool>visited(n,0);
        vector<bool>dfsvisit(n,0);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                bool ans=dfs(i,visited,dfsvisit,map);
                if(ans==true)
                return false;
            }
        }
        return true;
    }
};