class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int>q;
        unordered_set<int>visited,foundbox;
        int ans=0;
        for(int i:initialBoxes)
        {
            if(status[i] && !visited.count(i))
            {
                ans+=candies[i];
                visited.insert(i);
                q.push(i);
            }
           
                foundbox.insert(i);
         
        }
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            for(int i:containedBoxes[a])
            {
                if(status[i]==1 && !visited.count(i))
                {
                     ans+=candies[i];
                    visited.insert(i);
                    q.push(i);
                }
               
                    foundbox.insert(i);
                
            }
            for(int i:keys[a])
            {
                status[i]=1;
                if(foundbox.count(i)  && !visited.count(i))
                {
                    ans+=candies[i];
                    visited.insert(i);
                    q.push(i);
                }
            }

        }
        return ans;
    }
};