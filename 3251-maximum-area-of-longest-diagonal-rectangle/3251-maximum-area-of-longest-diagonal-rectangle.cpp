class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        int ind=-1;
        double maxi=-1;
        int w=0;
        for(auto i:d)
        {
            int t=pow(i[0],2);
            int m=pow(i[1],2);
            int s=t+m;
            double l=sqrt(s);
            if(maxi<l)
            {
                maxi=l;
                ind=w;
            }
            if(maxi==l)
            {
                if((d[ind][0] * d[ind][1]) < (d[w][0]*d[w][1]))
                ind=w;
            }
            w++;
        }
        return d[ind][0]*d[ind][1];
    }
};