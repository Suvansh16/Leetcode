class Solution {
public:
void dfs(int start,int par,vector<int>&mark,unordered_map<int,vector<int>>&map,bool val)
{
    mark[start]=val;
    for(int i:map[start])
    {
        if(i!=par)
        {
            dfs(i,start,mark,map,!val);
        }
    }
}
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>>map1;
        unordered_map<int,vector<int>>map2;
        for(auto i:edges1)
        {
            map1[i[0]].push_back(i[1]);
            map1[i[1]].push_back(i[0]);
        }
        for(auto i:edges2)
        {
            map2[i[0]].push_back(i[1]);
            map2[i[1]].push_back(i[0]);
        }
        int n=edges1.size(),m=edges2.size();
        vector<int>mark1(n+1,-1),mark2(m+1,-1);
        dfs(0,-1,mark1,map1,0);
        dfs(0,-1,mark2,map2,0);
        int countzero1=0,countone1=0,countzero2=0,countone2=0;
        for(int i:mark1)
        {
            if(i==0)
            countzero1++;
            else
            countone1++;
        }
         for(int i:mark2)
        {
            if(i==0)
            countzero2++;
            else
            countone2++;
        }
        vector<int>result(n+1,0);
        int l=max(countone2,countzero2);
        for(int i=0;i<n+1;i++)
        {
            if(mark1[i]==0)
            result[i]=countzero1+l;
            else
            result[i]=countone1+l;
        }
        return result;
    }
};