/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
unordered_map<Node*,Node*>map;
void dfs(Node *node,Node*clonenode)
{
    for(Node*a:node->neighbors)
    {
        if(map.find(a)==map.end())
        {
            Node*newnode=new Node(a->val);
            map[a]=newnode;
            clonenode->neighbors.push_back(newnode);
            dfs(a,newnode);
        }
        else
        {
            clonenode->neighbors.push_back(map[a]);
        }
    }
}
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        return NULL;
        Node* clonenode=new Node(node->val);
        map[node]=clonenode;
        dfs(node,clonenode);
        return clonenode;
    }
};