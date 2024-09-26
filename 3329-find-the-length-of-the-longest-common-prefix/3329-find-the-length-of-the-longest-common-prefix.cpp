struct Trienode{
    char digit;
    Trienode*children[10];

};
class Solution {
public:
Trienode*getnode()
{
    Trienode*node=new Trienode;
    for(int i=0;i<10;i++)
    {
        node->children[i]=nullptr;
    }
    return node;
}
void insert(int num,Trienode*root)
{
    Trienode*crawl=root;
    string numstr=to_string(num);
    for(char ch:numstr)
    {
        int idx=ch-'0';
        if(!crawl->children[idx])
        {
            crawl->children[idx]=getnode();
        }
        
            crawl=crawl->children[idx];
    }
}
int search(int num,Trienode*root)
{
    Trienode*crawl=root;
    string numstr=to_string(num);
    int length=0;
    for(char ch:numstr)
    {
        int idx=ch-'0';
        if(crawl->children[idx])
        {
            length++;
            crawl=crawl->children[idx];
        }
        else
        {
            break;
        }
    }
    return length;
}
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        Trienode*root=getnode();
        for(int num:arr1)
        {
            insert(num,root);
        }
        int result=0;
        for(int num:arr2)
        {
            result=max(result,search(num,root));
        }
        return result;
    }

};
