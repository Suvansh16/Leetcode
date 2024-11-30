class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>>map;
         //calculate indegree and outdegree
         unordered_map<int,int>indegree,outdegree;
        
        for(vector<int>&v:pairs)
        {
            map[v[0]].push_back(v[1]);
            outdegree[v[0]]++;
            indegree[v[1]]++;

        }
       
       
        
        //find the start node of euler path
        int startnode=-1;
        for(auto it:map)
        {
            int node=it.first;

            int diff=outdegree[node]-indegree[node];
            if(diff==1)
            {
                startnode=node;
                break;
            }
        }
        //if no node is startnode then take the first node as start node
        if(startnode==-1)
        startnode=pairs[0][0];
        //do the dfs;
        vector<int>eulerpath;//to store my euler path;
        stack<int>st;   //to perform dfs;
        st.push(startnode);
        while(!st.empty())
        {
            int curr=st.top();
            if(!map[curr].empty())
            {
                int ngbr=map[curr].back();
                st.push(ngbr);
                map[curr].pop_back();
            }
            else
            {
                eulerpath.push_back(curr);
                st.pop();
            }
        }
        //build your result
        reverse(eulerpath.begin(),eulerpath.end());
        vector<vector<int>>ans;
        for(int i=1;i<eulerpath.size();i++)
        {
            ans.push_back({eulerpath[i-1],eulerpath[i]});
        }
        return ans;
    }
};