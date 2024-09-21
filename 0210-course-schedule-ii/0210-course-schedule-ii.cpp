 class Solution {
public:
vector<int> bfs(unordered_map<int,vector<int>>map,vector<vector<int>>& prerequisites,vector<int>&indegree)
{
     vector<int>ans;
    queue<int>q;
    int count=0;
    for(int i=0;i<indegree.size();i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    while(!q.empty())
    {
        int a=q.front();
        ans.push_back(q.front());
        q.pop();
        count++;
        for(auto i:map[a])
        {
            indegree[i]--;
            if(indegree[i]==0)
            q.push(i);
        }
    }
    if(count==indegree.size())
    return ans;
    return {};

}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        unordered_map<int,vector<int>>map;
        vector<int>indegree(numCourses,0);
        int n=prerequisites.size();
        for(int i=0;i<n;i++)
        {
            map[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
       
        return bfs(map,prerequisites,indegree);

    }
};