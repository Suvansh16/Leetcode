class Solution {
public:
void dfs(int a,unordered_map<int,int>&map,vector<int>&v1,vector<bool>&visited)
{
    
    
    visited[a]=true;
    int v=map[a];
   if(v!=-1 && visited[v]==false)
   {
    visited[v]=true;
    v1[v]=1+v1[a];
    dfs(v,map,v1,visited);
   }

}
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<bool>visited(n,false);
        vector<bool>visited2(n,false);
        unordered_map<int,int>map;
        int k=0;
        for(int i:edges)
        {
            map[k]=i;
            k++;
        }
        vector<int>v1(n,INT_MAX);
        vector<int>v2(n,INT_MAX);
        v1[node1]=0;
        v2[node2]=0;
        dfs(node1,map,v1,visited);
      
        dfs(node2,map,v2,visited2);
        int maxdist=INT_MAX;
        int result=-1;
        for(int i=0;i<v1.size();i++)
        {
            int dist=max(v1[i],v2[i]);
            if(maxdist>dist)
            {
            maxdist=dist;
            result=i;
            }
        }
       return result;
        


    }
};