class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        //approach apply binary tree properties
        //sabhi ka ek hi parent except for one
        //no disconnected component apply bfs for this
        unordered_map<int ,int>parent;
        unordered_map<int,vector<int>>adjlist;
        for(int i=0;i<n;i++)
        {
            
            int leftc=leftChild[i];
            int rightc=rightChild[i];
            if(leftc!=-1)
            {
                adjlist[i].push_back(leftc);
                if(parent.find(leftc)!=parent.end())
                return false;
                parent[leftc]=i;
            }
            if(rightc!=-1)
            {
                 adjlist[i].push_back(rightc);
                if(parent.find(rightc)!=parent.end())
                return false;
                parent[rightc]=i;
            }
        }
        int root=-1;
        for(int i=0;i<n;i++)
        {
              if(parent.find(i)==parent.end())
              {
                 if(root!=-1)
               {
                return false;
               }
               root=i;
              }
        }
        if(root==-1)
        return false;
        //applying bfs traversal 
        int count=0;
        queue<int>q;
        unordered_map<int,bool>visited;
        q.push(root);
        visited[root]=true;
        count=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int &v:adjlist[node])
            {
                if(visited[v]==true)
                {
                    return false;
                }
                if(!visited[v])
                {
                    visited[v]=true;
                    q.push(v);
                    count++;
                }
            }
        }
        if(count==n)
        return true;
        return false;

    }
};