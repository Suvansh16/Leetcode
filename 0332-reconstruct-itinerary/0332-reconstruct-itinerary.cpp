class Solution {
public:
unordered_map<string, priority_queue<string,vector<string>,greater<string>>>map;
vector<string>result;
void solve(string start)
{
    
    auto &i=map[start];
    while(!i.empty())
    {
        string a=i.top();
        i.pop();
        solve(a);
    }
    result.push_back(start);

}
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto i:tickets)
        {
            map[i[0]].push(i[1]);

        }
        solve("JFK");
        reverse(result.begin(),result.end());
        return result;
    }
};