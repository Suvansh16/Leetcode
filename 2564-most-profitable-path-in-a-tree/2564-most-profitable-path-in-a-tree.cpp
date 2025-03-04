class Solution {
public:
unordered_map<int,vector<int>>map;
int solve(vector<int>&bob_path,int currnode,int parent,int timestamp,int currscore,vector<int>&amount)
{
    if(bob_path[currnode]==-1 || bob_path[currnode]>timestamp)
    currscore+=amount[currnode];
    else if(bob_path[currnode]==timestamp)
    currscore+=(amount[currnode]/2);
    if(map[currnode].size()==1 && currnode!=0)
    return currscore;
    int max_score=INT_MIN;
    for(int i:map[currnode])
    {
        if(i!=parent)
        {
            max_score=max(max_score,solve(bob_path,i,currnode,timestamp+1,currscore,amount));
        }
    }
    return max_score;

}
bool  bob_path_follow(int start_node,int parent,vector<int>&path,int dest)
{
    if(start_node==dest)
    return true;
    for(int i:map[start_node])
    {
        if(i!=parent){
        path.push_back(start_node);
        if( bob_path_follow(i,start_node,path,dest))
        return true;
        path.pop_back();
        }
    }
    return false;

}
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        for(vector<int>&edge:edges)
        {
            map[edge[0]].push_back(edge[1]);
            map[edge[1]].push_back(edge[0]);
        }
        int n=amount.size();
        vector<int>bob_path(n,-1);
        vector<int>path;
        bob_path_follow(bob,-1,path,0);
        for(int i=0;i<path.size();i++)
        {
            bob_path[path[i]]=i;
        }

        return solve(bob_path,0,-1,0,0,amount);
        
    }
};