class Solution {
public:
vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
int mintime=INT_MAX;
vector<vector<int>>minreach;
void solve(int i,int j,int n,int m,int time,vector<vector<int>>&grid,vector<vector<bool>>&visited)
{
   if(time>=minreach[i][j])
   return ;
   minreach[i][j]=time;
    if(i==n && j==m)
    {
        mintime=min(time,mintime);
        return ;
    }
     visited[i][j]=true;
    
    for(auto &dir:directions)
    {
        int a=dir[0];
        int b=dir[1];
        int new_i=i+a;
        int new_j=j+b;
        if(new_i<=n && new_j<=m && new_i>=0 && new_j>=0 && !visited[new_i][new_j])
        {
            if(time>grid[new_i][new_j])
            {
                solve(new_i,new_j,n,m,time+1,grid,visited);
            }
            else
            {
                solve(new_i,new_j,n,m,grid[new_i][new_j]+1,grid,visited);
            }
        }

    }
    visited[i][j]=false;
    
}
    int minTimeToReach(vector<vector<int>>& moveTime) {
         int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<bool>>visited(moveTime.size(),vector<bool>(moveTime[0].size(),false));
         minreach = vector<vector<int>>(n, vector<int>(m, INT_MAX));
                

        solve(0,0,moveTime.size()-1,moveTime[0].size()-1,0,moveTime,visited);
        return mintime;
    }
};