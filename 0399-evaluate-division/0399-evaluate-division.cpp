class Solution {
public:
void  dfs(unordered_map<string,vector<pair<string,double>>>&map,string src,string dest,double &ans,double product,unordered_set<string>&visited)
{
    if(visited.find(src)!=visited.end())
    return;
    visited.insert(src);
    if(src==dest)
    {
        ans=product;
        return;
    }
    for(auto &p:map[src])
    {
        string v=p.first;
        double val=p.second;
        dfs(map,v,dest,ans,product*val,visited);
    }
}
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double>result;
        unordered_map<string,vector<pair<string,double>>>map;
      
        for(int i=0;i<equations.size();i++)
        {
            map[equations[i][0]].push_back({equations[i][1],values[i]});
            map[equations[i][1]].push_back({equations[i][0],1/values[i]});
           
        }
        for(int k=0;k<queries.size();k++)
        {
            string src=queries[k][0];
            string dest=queries[k][1];
            double ans=-1.0;
            double product=1.0;
            if(map.find(src)!=map.end() && map.find(dest)!=map.end())
            {
                unordered_set<string>visited;
                dfs(map,src,dest,ans,product,visited);
            }
            result.push_back(ans);
        }
        return result;

    }
};