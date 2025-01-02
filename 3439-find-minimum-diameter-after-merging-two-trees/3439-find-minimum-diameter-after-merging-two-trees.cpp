class Solution {
public:
pair<int,int>BFS(unordered_map<int,vector<int>>&map,int node)
{
    int farthestnode=0;
    int diameter=0;
    queue<int>q;
    q.push(node);
    unordered_map<int,bool>visited;
    visited[node]=true;
    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            int curr=q.front();
            farthestnode=curr;
            q.pop();
            for(auto &ngbr:map[curr])
            {
                if(visited[ngbr]==false)
                {
                    q.push(ngbr);
                    visited[ngbr]=true;
                }
            }
        }
        if(!q.empty())
        {
            diameter++;
        }
    }   
    return {farthestnode,diameter};
}
int finddia(unordered_map<int,vector<int>>map)
{
 //step-1 find the farthest node from a random node - 0   
    auto [farthestnode,dist]=BFS(map,0);
      //step-2 : the farthestNode we got above is nothing but one end of the diameter of adj

        //step-3 : Find the farthestnode from the node we got above , that will be the other end of diameter - diameter
    auto[othernode,diameter]=BFS(map,farthestnode);
    return diameter;
}
unordered_map<int,vector<int>>buildadj(vector<vector<int>>& edges1)
{
    unordered_map<int,vector<int>>map;
    for(auto &v:edges1)
    {
        map[v[0]].push_back(v[1]);
        map[v[1]].push_back(v[0]);
    }
    return map;
}
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>>map1=buildadj(edges1);
        unordered_map<int,vector<int>>map2=buildadj(edges2);

        int dia1=finddia(map1);
        int dia2=finddia(map2);

        return max({dia1,dia2,((dia1+1)/2) + ((dia2+1)/2) +1});
    }
};