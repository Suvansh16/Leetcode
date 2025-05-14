class Solution {
public:
const int mod=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<int>map(26,0);
        for(char i:s)
        map[i-'a']++;
        for(int i=1;i<=t;i++)
        {
            vector<int>temp(26,0);
            for(int j=0;j<26;j++)
            {
                if(map[j]!=0 && j!=25)
                {
                    temp[j+1]=(temp[j+1]+map[j])%mod;
                }
                else if(map[j]!=0 && j==25)
                {
                    temp[0]=(temp[0]+map[j])%mod;
                    temp[1]=(temp[1]+map[j])%mod;
                }
            }
            map=temp;
        }
        int result=0;
        for(int i=0;i<26;i++)
        {
            result=(result+map[i])%mod;
        }
        return result;
    }
};