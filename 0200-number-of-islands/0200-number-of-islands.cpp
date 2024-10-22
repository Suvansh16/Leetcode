class Solution {
public:
int n,m;
vector<vector<int>>directions={{1,0},{-1,0},{0,-1},{0,1}};
void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>&visited)
{
      if( i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]=='0')
    return;
    visited[i][j]=true;
    for(auto dir:directions)
    {
        int new_i=i+dir[0];
        int new_j=j+dir[1];
        if(new_i>=0 && new_i<n && new_j>=0 && new_j<m &&!visited[new_i][new_j] && grid[new_i][new_j]=='1')
        {
            dfs(new_i,new_j,grid,visited);
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
         m=grid[0].size();

        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==false && grid[i][j]=='1')
                {
                    dfs(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
};