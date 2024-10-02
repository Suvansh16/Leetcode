class Solution {
public:

int DFS(unordered_map<int,vector<int>>&map,vector<bool>&hasapple,int curr,int parent)
{
   int time=0;
   for(int&child:map[curr])
   {
    if(child==parent)
    continue;
    int time_from_child= DFS(map,hasapple,child,curr);
    if(time_from_child>0 || hasapple[child]==true)
    {
        time+=2+time_from_child;
    }
   }
   return time;
}
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int>result(n,0);
        unordered_map<int,vector<int>>map;
        for(vector<int>&e:edges)
        {
            map[e[0]].push_back(e[1]);
            map[e[1]].push_back(e[0]);
        }
        return DFS(map,hasApple,0,-1);
    
    }
};