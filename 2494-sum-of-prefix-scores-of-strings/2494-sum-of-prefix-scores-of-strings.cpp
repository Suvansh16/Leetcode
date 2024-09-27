struct Trienode{
int digit=0;
Trienode*children[26];
};

class Solution {
public:
Trienode*getnode()
{
    Trienode*crawl=new Trienode;
    for(int i=0;i<26;i++)
    {
        crawl->children[i]=nullptr;
    }
    crawl->digit=0;
    return crawl;
}
void insert(string s,Trienode*root)
{
    Trienode*crawl=root;
    for(char &ch:s)
    {
        int idx=ch-'a';
        if(!crawl->children[idx])
        {
            crawl->children[idx]=getnode();

        }
        crawl->children[idx]->digit++;
        crawl=crawl->children[idx];
    }
}
int search(string s,Trienode*root)
{
    Trienode*crawl=root;
    int ans=0;
    for(char &ch:s)
    {
        int idx=ch-'a';
        if(crawl->children[idx])
        {
            ans+=crawl->children[idx]->digit;
            crawl=crawl->children[idx];
        }
        else
        break;
    }
    return ans;
}
    vector<int> sumPrefixScores(vector<string>& words) {
        Trienode*root=getnode();
        for(string s:words)
        {
            insert(s,root);
        }
        vector<int>ans;
        for(string s:words)
        {
            ans.push_back(search(s,root));
        }
        return ans;
    }
};