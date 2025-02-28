class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>pq;
        int max_can_reach=startFuel;
        int count=0;
        int i=0;
        
    while(i<stations.size() && max_can_reach<target)
    {
        if(max_can_reach<stations[i][0])
        {
            if(pq.empty())
            return -1;
            max_can_reach+=pq.top();
            pq.pop();
            count++;
        }
        else
        {
            pq.push(stations[i][1]);
            i++;
        }
    }
    while(!pq.empty() && max_can_reach<target)
    {
        max_can_reach+=pq.top();
        count++;
        pq.pop();
    }
    if(max_can_reach<target)
    return -1;
        return count;

    }
};