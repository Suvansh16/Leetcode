class Solution {
public:
vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int steps=0;
        while(!q.empty())
        {
            int l=q.size();
            while(l--)
            {
                pair<int,int>p=q.front();
                q.pop();
                int a=p.first;
                int b=p.second;
                if((a==0 || b==0 || a==n-1 || b==m-1) && p!=make_pair(entrance[0],entrance[1]))
                {
                    return steps;
                }
                for(auto &dir:directions)
                {
                    int new_a=a+dir[0];
                    int new_b=b+dir[1];
                    if(new_a>=0 && new_b>=0 && new_a<=n-1 && new_b<=m-1 && maze[new_a][new_b]!='+')
                    {
                        q.push({new_a,new_b});
                        maze[new_a][new_b]='+';
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};