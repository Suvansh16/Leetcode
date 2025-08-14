class Solution {
public:
vector<int>parent;
int components;
int find(int x)
{
    if(parent[x]==x)
    return x;
    return parent[x]=find(parent[x]);
}
bool union_find(int par,int child)
{
    int child_par=find(child);
    if(child_par!=child)
    return false;
    int par_par=find(par);
    if(par_par==child_par)
    return false;
    parent[child]=par;
    components--;
    return true;
}
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        components=n;
        parent.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            if(leftChild[i]>=0 && !union_find(i,leftChild[i]))
            return false;
            if(rightChild[i]>=0 && !union_find(i,rightChild[i]))
            return false;
        }
        return components==1;
    }
};