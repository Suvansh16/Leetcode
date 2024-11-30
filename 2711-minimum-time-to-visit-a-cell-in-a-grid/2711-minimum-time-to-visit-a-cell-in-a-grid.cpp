class Solution {
public:
vector<vector<int>>directions={{-1,0},{1,0},{0,1},{0,-1}};
int n,m;
typedef pair<int,pair<int,int>> p;
    int minimumTime(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        if(grid[0][1]>1  && grid[1][0]>1)
        return -1;

        vector<vector<int>>result(n,vector<int>(m,INT_MAX));
        priority_queue<p,vector<p>,greater<p>>pq;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        result[0][0]=0;
        pq.push({0,{0,0}});
        visited[0][0]=true;
        while(!pq.empty())
        {
            auto l=pq.top();
            pq.pop();
            int a=l.first;
            int b=l.second.first;
            int c=l.second.second;

            for(auto dir:directions)
            {
                int new_i=dir[0]+b;
                int new_j=dir[1]+c;
                if(new_i<0 || new_j<0 || new_i>=n || new_j>=m || visited[new_i][new_j])
                continue;
                visited[new_i][new_j]=true;
                int extrawait=(grid[new_i][new_j]-a)%2==0?1:0;
                int time=max(a+1,grid[new_i][new_j]+extrawait);
                result[new_i][new_j]=time;
                pq.push({time,{new_i,new_j}});

              
            }
        }

        return result[n-1][m-1];
    }
};