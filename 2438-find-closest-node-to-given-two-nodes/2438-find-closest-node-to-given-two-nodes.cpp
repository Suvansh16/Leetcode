class Solution {
public:
void solve(int node,unordered_map<int,int>&map,vector<bool>&visited,vector<int>&v)
{   visited[node]=true;
    int t=map[node];
    if(t!=-1 && !visited[t])
    {
        v[t]=1+v[node];
        solve(t,map,visited,v);
    } 
}
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<bool>visited(n,false);
        vector<int>v1(n,INT_MAX),v2(n,INT_MAX);
        v1[node1]=0;
        v2[node2]=0;
        unordered_map<int,int>map;
        for(int i=0;i<n;i++)
        {
            map[i]=edges[i];
        }
        solve(node1,map,visited,v1);
        fill(visited.begin(),visited.end(),false);
        solve(node2,map,visited,v2);
        int ans=-1;
        int dis=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(v1[i]==INT_MAX || v2[i]==INT_MAX)
            continue;
            int t=max(v1[i],v2[i]);
            if(dis>t)
            {
                dis=t;
                ans=i;
            }
        }
        return ans;
    }
};