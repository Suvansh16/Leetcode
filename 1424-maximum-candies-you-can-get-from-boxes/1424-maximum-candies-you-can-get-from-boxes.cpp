class Solution {
public:
int solve(int start,vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, unordered_set<int>&visited,unordered_set<int>&foundbox)
{
    if(visited.count(start))
    return 0;
    if(status[start]==0)
    {
        foundbox.insert(start);
        return 0;

    }
    visited.insert(start);
    int ans=candies[start];
    for(int i:containedBoxes[start])
    {
        ans+=solve(i,status,candies,keys,containedBoxes,visited,foundbox);
    }
    for(int i:keys[start])
    {
        status[i]=1;
        if(foundbox.count(i))
        {
            ans+=solve(i,status,candies,keys,containedBoxes,visited,foundbox);
        }
    }
    return ans;
}
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        unordered_set<int>visited;
        unordered_set<int>foundbox;
        int ans=0;
        for(int i:initialBoxes)
        {
            if(!visited.count(i))
            ans+=solve(i,status,candies,keys,containedBoxes,visited,foundbox);
        }
        return ans;
    }
};