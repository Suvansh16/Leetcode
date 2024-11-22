class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int count=0;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            int result=0;
            vector<int>inverted(m,0);
            for(int k=0;k<m;k++)
            {
                inverted[k]=1-matrix[i][k];
            }
            for(vector<int>rows:matrix)
            {
                if(rows==inverted || rows==matrix[i])
                result++;
            }
            count=max(count,result);
        }
        return count;
    }
};