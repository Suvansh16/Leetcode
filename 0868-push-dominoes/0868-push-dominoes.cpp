class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes='L'+dominoes+'R';
        int prev=0;
        int span=0;
        string res;
        for(int i=1;i<dominoes.size();i++)
        {
            if(dominoes[i]=='.')
            continue;
            int span=i-prev-1;
            if(prev>0)
            res+=dominoes[prev];
            if(dominoes[i]==dominoes[prev])
            {
                res+=string(span,dominoes[prev]);
            }
            else if(dominoes[i]=='R' && dominoes[prev]=='L')
            res+=string(span,'.');
            else
            {
                res+=string(span/2,'R');
                res+=string(span%2,'.');
                res+=string(span/2,'L');
            }
            prev=i;
        }
        return res;
    }
};