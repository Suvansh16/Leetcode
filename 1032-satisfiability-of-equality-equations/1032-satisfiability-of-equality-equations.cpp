class Solution {
public:
vector<int>parent;
vector<int>rank;
int find(int i)
{
    if(i==parent[i])
    return i;
    return parent[i]=find(parent[i]);

}
void Union(int x,int y)
{
    int x_parent=parent[x];
    int y_parent=parent[y];
    if(rank[x_parent]>rank[y_parent])
    {
        parent[y_parent]=x_parent;
    }
    else if(rank[x_parent]<rank[y_parent])
    {
        parent[x_parent]=y_parent;
    }
    else
    {
        parent[x_parent]=y_parent;
        rank[y_parent]+=1;
    }
}
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
        }
        for(string &s:equations)
        {
            if(s[1]=='=')
            {
                Union(s[0]-'a',s[3]-'a');
            }
        }
          for(string &s:equations)
        {
            if(s[1]!='=')
            {
               int a=s[0]-'a';
               int b=s[3]-'a';
               int a_parent=find(a);
               int b_parent=find(b);
               if(a_parent==b_parent)
               return false;
            }
        }
        return true;

    }
};