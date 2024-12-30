class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<int>v(values.size(),0);
        v[0]=values[0];
        for(int i=1;i<values.size();i++)
        {
            v[i]=max(v[i-1],values[i]+i);
        }
        int ans=0;
        for(int j=1;j<values.size();j++)
        {
            ans=max(ans,v[j-1]+values[j]-j);
        }
        return ans;
    }
};