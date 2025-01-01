class Solution {
public:
int m,k;
const int mod=1e9+7;
int t[1001][1001];
int solve(int i,int j,vector<vector<long long>>&freq,string &target)
{
    if(i==m)
    return 1;
    if(j==k)
    return 0;
    if(t[i][j]!=-1)
    return t[i][j];
    int not_taken=solve(i,j+1,freq,target);
    int taken=(freq[target[i]-'a'][j]*solve(i+1,j+1,freq,target))%mod;
    return t[i][j]=(not_taken+taken)%mod;
}
    int numWays(vector<string>& words, string target) {
        k=words[0].length();
        m=target.length();
        vector<vector<long long>>freq(26,vector<long long>(k));
        for(int col=0;col<k;col++)
        {
            for(string word:words)
            {
                freq[word[col]-'a'][col]++;
            }

        }
        memset(t,-1,sizeof(t));
        return solve(0,0,freq,target);
    }
};