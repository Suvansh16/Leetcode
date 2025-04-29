class Solution {
public:
vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>ans(queries.size());
        vector<pair<int,int>>q;
        for(int i=0;i<queries.size();i++)
        {
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        int count=0;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        pq.push({grid[0][0],{0,0}});
        visited[0][0]=true;
        int idx=0;
        for(auto &[val,i]:q)
        {
            while(!pq.empty() && pq.top().first<val)
            {
                auto [currval,coord]=pq.top();
                pq.pop();
                count++;
                int x=coord.first,y=coord.second;
                for(auto &d:directions)
                {
                    int nx=x+d[0],ny=y+d[1];
                    if(nx>=0 && ny>=0 && nx<m && ny<n && !visited[nx][ny])
                    {
                        visited[nx][ny]=true;
                        pq.push({grid[nx][ny],{nx,ny}});
                    }
                }
            }
            ans[i]=count;
        }
        return ans;
    }
};