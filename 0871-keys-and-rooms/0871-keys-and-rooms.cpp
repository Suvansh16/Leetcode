class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visited(n,false);
        queue<vector<int>>q;
        q.push(rooms[0]);
        visited[0]=true;
        while(!q.empty())
        {
           
            vector<int>a=q.front();
            q.pop();
             int size=a.size();
            while(size--)
            {
                
                if(!visited[a[size]])
                {
                    q.push(rooms[a[size]]);
                    visited[a[size]]=true;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            return false;
        }
        return true;
    }
};