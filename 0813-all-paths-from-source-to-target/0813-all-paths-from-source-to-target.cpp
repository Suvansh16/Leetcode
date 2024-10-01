class Solution {
public:
int n;
void solve(vector<vector<int>>&ans,vector<int>output,unordered_map<int,vector<int>>&map,int start)
{
    if(start==n-1)
    {
        ans.push_back(output);
        return ;
    }
    
   
    for(auto i:map[start])
    {
       
            output.push_back(i);
            solve(ans,output,map,i);
            output.pop_back();
      
    }


}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>map;
         n=graph.size();
        for(int i=0;i<n;i++)
        {
            vector<int>a=graph[i];
            for(auto s:a)
            {
                map[i].push_back(s);
            }
        }
        vector<vector<int>>ans;
        
       vector<int> output = {0};

        solve(ans,output,map,0);
        return ans;

    }
};