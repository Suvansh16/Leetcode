class Solution {
public:
void dfs(unordered_map<int,int>&map,vector<int>&v1,vector<bool>&visited,int a)
{
    visited[a]=true;
    int l=map[a];
    if(l!=-1 && !visited[l]  )
    {
        visited[l]=true;
        v1[l]=1+v1[a];
        dfs(map,v1,visited,l);
    }
}
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<bool>visited1(n,false);
        vector<bool>visited2(n,false);
        vector<int>v1(n,INT_MAX);
        vector<int>v2(n,INT_MAX);
        unordered_map<int,int>map;
        for(int i=0;i<n;i++)
        {
            map[i]=edges[i];
        }
        v1[node1]=0;
        v2[node2]=0;
        dfs(map,v1,visited1,node1);
        dfs(map,v2,visited2,node2);
        int maxans=INT_MAX;
        int ind=-1;
        for(int i=0;i<n;i++)
        {
            int t=max(v1[i],v2[i]);
            if(maxans>t)
            {
                maxans=t;
                ind=i;

            }
        }
        return ind;

    }
};