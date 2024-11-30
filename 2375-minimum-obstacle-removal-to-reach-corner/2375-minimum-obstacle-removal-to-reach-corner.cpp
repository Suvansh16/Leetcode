class Solution {
public:
typedef pair<int,pair<int,int>> p;
int n,m;
vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    int minimumObstacles(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>result(n,vector<int>(m,INT_MAX));
        priority_queue<p,vector<p>,greater<p>>pq;
        result[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
           auto l=pq.top();
           pq.pop();
           int a=l.first;
           int b=l.second.first;
           int c=l.second.second;
           for(auto dir:directions)
           {
            int new_i=b+dir[0];
            int new_j=c+dir[1];
            if(new_i<0 || new_j<0 || new_i>=n || new_j>=m)
            continue;
            int s=grid[new_i][new_j]==1?1:0;
            if(result[new_i][new_j]>a+s)
            {
                result[new_i][new_j]=a+s;
                pq.push({a+s,{new_i,new_j}});
            }
           }
        }
        return result[n-1][m-1];
    }
};