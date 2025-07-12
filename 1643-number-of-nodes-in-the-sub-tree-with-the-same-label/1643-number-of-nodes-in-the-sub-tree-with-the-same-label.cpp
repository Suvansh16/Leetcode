class Solution {
public:
vector<int>solve(int start,int parent,string &labels,unordered_map<int,vector<int>>&map,vector<int>&result)
{
    vector<int>my_count(26,0);
    char ch=labels[start];
    my_count[ch-'a']=1;
    for(auto i:map[start])
    {
        if(i!=parent)
        {
            vector<int>child(26,0);
            child=solve(i,start,labels,map,result);
            for(int i=0;i<26;i++)
            {
                my_count[i]+=child[i];
            }
        }
    }
    result[start]=my_count[ch-'a'];
    return my_count;
}
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int,vector<int>>map;
        for(auto i:edges)
        {
            map[i[0]].push_back(i[1]);
            map[i[1]].push_back(i[0]);
        }
        vector<int>result(n,0);
        solve(0,-1,labels,map,result);
        return result;
        
    }
};