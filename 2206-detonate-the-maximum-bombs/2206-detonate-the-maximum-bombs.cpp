class Solution {
public:
typedef long long LL;
void DFS( int i,unordered_set<int>&visited,unordered_map<int,vector<int>>&map)
{
 visited.insert(i);   
 for(int &v:map[i])
 {
    if(visited.find(v)==visited.end())
    DFS(v,visited,map);
 }
}
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        unordered_map<int,vector<int>>map;
        for (int i = 0; i < n; ++i) {
            LL x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;

                LL x2 = bombs[j][0], y2 = bombs[j][1];
                LL dx = x2 - x1, dy = y2 - y1;
                LL distSquared = dx * dx + dy * dy;
                LL r1Squared = r1 * r1;

                // If bomb j is within the range of bomb i
                if (r1Squared >= distSquared) {
                    map[i].push_back(j);
                }
            }
        }
        int result=0;
        unordered_set<int>visited;
        for(int i=0;i<n;i++)
        {
            DFS(i,visited,map);
            int count=visited.size();
            result=max(result,count);
            visited.clear();
        }
        return result;

    }
};