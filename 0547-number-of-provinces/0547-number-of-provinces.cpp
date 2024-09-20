class Solution {
public:
void BFS(vector<bool>&visited,int start,unordered_map<int,vector<int>>map)
{
    
     queue<int>q;
     q.push(start);
   while(!q.empty())
   {
    
    int a=q.front();
     visited[a]=true;
    q.pop();
    
        for(auto i:map[a])
        {
            if(!visited[i])
            q.push(i);
        }
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
                BFS(visited,i,map);
                  count++;

            }
          
        }

        return count;
    }
};