class Solution {
public:
typedef pair<int,int> p;
    int minTimeToReach(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        priority_queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        while(!q.empty())
        {
            int newdist=q.top().first;
            int b=q.top().second.first;
            int c=q.top().second.second;
            q.pop();
            if(b+1<n && dist[b+1][c]>max(newdist+1,a[b+1][c]+1)){
            q.push({max(newdist+1,a[b+1][c]+1),{b+1,c}});
            dist[b+1][c]=max(newdist+1,a[b+1][c]+1);
            }
            if(b-1>=0 && dist[b-1][c]>max(newdist+1,a[b-1][c]+1)){
            q.push({max(newdist+1,a[b-1][c]+1),{b-1,c}});
            dist[b-1][c]=max(newdist+1,a[b-1][c]+1);
            }
            if(c-1>=0 && dist[b][c-1]>max(newdist+1,a[b][c-1]+1)){
            q.push({max(newdist+1,a[b][c-1]+1),{b,c-1}});
            dist[b][c-1]=max(newdist+1,a[b][c-1]+1);
            }
            if(c+1<m && dist[b][c+1]>max(newdist+1,a[b][c+1]+1)){
            q.push({max(newdist+1,a[b][c+1]+1),{b,c+1}});
            dist[b][c+1]=max(newdist+1,a[b][c+1]+1);
            }
        }
        return dist[n-1][m-1];
    }
};