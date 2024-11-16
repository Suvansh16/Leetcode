class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>>map; //one route can present in many buses therefore vector banaya
        
        if(source==target)
        return 0;
        
       
        queue<int>q;
        for(int i=0;i<routes.size();i++)
        {
            for(int j=0;j<routes[i].size();j++)
            {
                map[routes[i][j]].push_back(i);
            }
        }
        unordered_set<int>visitedbus;
        for(int &i:map[source]){
        q.push(i);
        visitedbus.insert(i);
        }
        int count=0;
       
        while(!q.empty())
        {
            count++;
            int size=q.size();
            while(size--)
            {
                int a=q.front();
                q.pop();
               
                for(int i=0;i<routes[a].size();i++)
                {
                    if(routes[a][i]==target)
                    return count;
               }
               for(int i=0;i<routes[a].size();i++){
               for(int &j:map[routes[a][i]])
               {
                 if(visitedbus.find(j)==visitedbus.end()){
                    q.push(j);
                    visitedbus.insert(j);
                 }
                
               }
               }
            }
        }
        return -1;
    }
};