class Solution {
public:
void DFS(vector<bool>&visited,int start,unordered_map<int,vector<int>>map)
{
     visited[start]=true;
    for(auto i:map[start])
    {
        if(!visited[i])
        DFS(visited,i,map);
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected[0].size();
        unordered_map<int,vector<int>>map;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if (isConnected[i][j] == 1 && i != j) {
                    map[i + 1].push_back(j + 1);  // Nodes are indexed 1-based
                }
            }
           
        }
        int count=0;
        vector<bool>visited(n+1,false);
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                DFS(visited,i,map);
                  count++;

            }
          
        }
        return count;
    }
};