class Solution {
public:
vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
int m,n;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m=image.size();
        n=image[0].size();
        vector<vector<int>>visited(m,vector<int>(n,false));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        visited[sr][sc]=true;
        int initial=image[sr][sc];
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                pair<int,int>p=q.front();
                q.pop();
                image[p.first][p.second]=color;
                for(auto &dir:directions)
                {
                    int new_i=p.first+dir[0];
                    int new_j=p.second+dir[1];
                    if(new_i>=0 && new_j>=0 && new_i<m && new_j<n && !visited[new_i][new_j] && image[new_i][new_j]==initial)
                    {
                        visited[new_i][new_j]=true;
                        q.push({new_i,new_j});
                    }
                }
            }
        }
        return image;

    }
};