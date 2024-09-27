struct Trienode{
 string temp="";
Trienode*children[26];
bool isend;
};

class Solution {
public:
int n,m;
vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
vector<string>result;
Trienode*getnode()
{
    Trienode*crawl=new Trienode;
    for(int i=0;i<26;i++)
    {
        crawl->children[i]=nullptr;

    }
    crawl->temp="";
    crawl->isend=false;

    return crawl;
}
void insert(string s,Trienode*root)
{
    Trienode*crawl=root;
    for(char ch:s)
    {
        if(!crawl->children[ch-'a'])
        crawl->children[ch-'a']=getnode();
        crawl=crawl->children[ch-'a'];
    }
    crawl->isend=true;
    crawl->temp=s;

}
void findres(Trienode*root,int i,int j, vector<vector<char>>& board)
{
    if(i<0 || j<0 || i>=n || j>=m)
    return;
    if(board[i][j]=='$' || !root->children[board[i][j]-'a'])
    return;
    root=root->children[board[i][j]-'a'];
    if(root->isend)
    {
        result.push_back(root->temp);
        root->isend=false;
    }
    char temp=board[i][j];
    board[i][j]='$';
    for(vector<int>&dir:directions)
    {
        int fir=i+dir[0];
        int sec=j+dir[1];
        findres(root,fir,sec,board);
    }
    board[i][j]=temp;

}
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trienode*root=getnode();
        for(string s:words)
        {
            insert(s,root);
        }
         n=board.size();
         m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(root->children[board[i][j]-'a'])
                {
                    findres(root,i,j,board);
                }
            }
        }
        return result;
     }
};