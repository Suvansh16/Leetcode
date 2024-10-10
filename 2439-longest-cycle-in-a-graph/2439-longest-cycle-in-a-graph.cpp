class Solution {
public:
int largest;
void dfs(int start,vector<bool>&inrecursion,vector<int>&count,vector<bool>&visited,unordered_map<int,int>&map)
{
    if(start==-1)
    return;
    visited[start]=true;
    inrecursion[start]=true;
    int v=map[start];
    if(v!=-1 && !visited[v])
    {
        count[v]=1+count[start];
        dfs(v,inrecursion,count,visited,map);

    }
    else if(v!=-1 && inrecursion[v]==true) {
        largest=max(largest,count[start]-count[v]+1);
        
        //cycle hai but recursion wala true hona chahiye
    }
     inrecursion[start]=false;
   
}
    int longestCycle(vector<int>& edges) {
        unordered_map<int,int>map;
        int n=edges.size();
        for(int i=0;i<n;i++)
        {
            map[i]=edges[i];
        }
        largest=-1;
        vector<bool>visited(n,false);
        vector<bool>inrecursion(n,false);
        vector<int>count(n,1);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,inrecursion,count,visited,map);
            }
        }
        return largest;
    }
};