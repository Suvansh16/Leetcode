class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>>map;
        if(source==target)
        return 0;
        for(int i=0;i<routes.size();i++)
        {
            for(int j:routes[i])
            map[j].push_back(i);
        }
        queue<int>q;
        unordered_set<int>visited_bus;
        for(int i:map[source])
        {
            q.push(i);
            visited_bus.insert(i);
        }
        int count=0;
        while(!q.empty())
        {
            count++;
            int size=q.size();
            while(size--)
            {
                int t=q.front();
                q.pop();
                for(int a:routes[t])
                {
                    if(a==target)
                    return count;
                }
                for(int a:routes[t])
                {
                    for(int j:map[a])
                    {
                        if(!visited_bus.count(j))
                        {
                            visited_bus.insert(j);
                            q.push(j);
                        }
                    }
                }
            }
        }
        return -1;
    }
};