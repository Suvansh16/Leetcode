class Solution {
public:
vector<vector<int>>directions={{1,0},{-1,0},{0,-1},{0,1},{1,-1},{1,1},{-1,-1},{-1,1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int i=0,j=0;
        int n=grid.size();
        if(grid[0][0]==1  || grid[n-1][n-1]==1)
        return -1;
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        q.push({i,j});
        visited[i][j]=true;
        int ans=1;
        while(!q.empty())
        {
            int size=q.size();
            while(size--){
            pair<int,int>p=q.front();
            q.pop();
            int a=p.first;
            int b=p.second;
            if(a==n-1 && b==n-1)
            return ans;
            for(auto &dir:directions)
            {
                int new_i=a+dir[0];
                int new_j=b+dir[1];
                if(new_i>=0 && new_j>=0 && new_i<n && new_j<n && !visited[new_i][new_j] && grid[new_i][new_j]!=1)
                {
                    visited[new_i][new_j]=true;
                    q.push({new_i,new_j});
                }
            }
            }
            ans++;

        }
        return -1;
    }
};