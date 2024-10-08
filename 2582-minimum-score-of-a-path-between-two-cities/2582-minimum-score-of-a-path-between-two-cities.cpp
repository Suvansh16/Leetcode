class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>map;
        for(int i=0;i<roads.size();i++)
        {
            map[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            map[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<int>ans(n+1,INT_MAX);
        ans[1]=0;
        queue<pair<int,int>>q;
        q.push({1,0});
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                pair<int,int>i=q.front();
                q.pop();
                int a=i.first;
                int b=i.second;
                for(pair<int,int>p:map[a])
                {
                    if(p.second<ans[p.first])
                    {
                        ans[p.first]=p.second;
                        q.push({p.first,p.second});

                    }
                }
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<=n;i++)
        {
            if(i==1)
            continue;
            mini=min(mini,ans[i]);
        }
        return mini;
    }
};