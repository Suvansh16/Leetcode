class Solution {
public:
vector<int>result;
void solve(int start,int prev,unordered_map<int,vector<int>>&map)
{
    result.push_back(start);
    for(int &v:map[start])
    {
        if(v!=prev)
        {
            solve(v,start,map);
        }
    }

}
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>map;
       for(auto i:adjacentPairs)
       {
        map[i[0]].push_back(i[1]);
        map[i[1]].push_back(i[0]);
       }
       int start;
       for(auto i:map)
       {
        if(i.second.size()==1)
        {
            start=i.first;
            break;
        }
       }
       solve(start,INT_MIN,map);
       return result;
    }
};