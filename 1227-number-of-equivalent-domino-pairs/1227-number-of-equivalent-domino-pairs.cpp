class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& d) {
        for(int i=0;i<d.size();i++)
        {
            int a=d[i][0];
            int b=d[i][1];
            if(a>b)
            swap(d[i][0],d[i][1]);
        }
        sort(d.begin(),d.end());
        int prev=0;
        int count=0;
        for(int i=1;i<d.size();i++)
        {
            if(d[i][0]==d[i-1][0] && d[i][1]==d[i-1][1])
            count+=(i-prev);
            else
            prev=i;
        }
        return count;
    }
};