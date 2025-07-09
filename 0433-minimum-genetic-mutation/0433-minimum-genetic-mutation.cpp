class Solution {
public:
int solve(string startGene,string endGene,unordered_set<string>&bank,unordered_set<string>&visited)
{
    if(startGene==endGene)
    return 0;
    int ans=INT_MAX;
    string genes="ACGT";

    for(int i=0;i<8;i++)
    {
        char original=startGene[i];
        for(char ch:genes)
        {
            if(ch==original)
            continue;
            startGene[i]=ch;
            if(bank.count(startGene)&& !visited.count(startGene))
            {
                visited.insert(startGene);
                int steps=solve(startGene,endGene,bank,visited);
                if(steps!=INT_MAX)
                ans=min(ans,1+steps);
                visited.erase(startGene);
            }
        }
        startGene[i]=original;
    }
    return ans;
}
    int minMutation(string startGene, string endGene, vector<string>& bankt) {
        unordered_set<string>bank(bankt.begin(),bankt.end());
        unordered_set<string>visited;
        if(!bank.count(endGene))
        return -1;
        visited.insert(startGene);
        int result=solve(startGene,endGene,bank,visited);
        return result==INT_MAX?-1:result;
    }
};