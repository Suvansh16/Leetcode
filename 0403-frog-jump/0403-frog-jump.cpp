class Solution {
public:
unordered_map<int,unordered_set<int>>dp;
bool solve(int start,int walk,vector<int>&stones,unordered_map<int,int>&index)
{
    if(start==stones.size()-1)
    return true;
    if(dp[start].count(walk))
    return false;
    dp[start].insert(walk);
    for(auto jump:{walk-1,walk,walk+1})
    {
        if(jump>0 && index.count(stones[start]+jump))
        {
            if(solve(index[stones[start]+jump],jump,stones,index))
            return true;
        }
    }
    return false;
}
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1)
        return false;
        
        unordered_map<int,int>index;
        for(int i=0;i<stones.size();i++)
        {
            index[stones[i]]=i;
        }
        return solve(0,0,stones,index);
    }
};