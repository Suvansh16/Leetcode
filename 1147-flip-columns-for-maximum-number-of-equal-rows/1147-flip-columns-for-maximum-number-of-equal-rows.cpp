class Solution {
public:
void flip(int col,vector<vector<int>>&temp,int row)
{
    for(int i=0;i<temp.size();i++)
    {
        temp[i][col]=temp[i][col]==1?0:1;
    }
}
int  count(vector<vector<int>>&temp)
{
    int res=0;
    for(int i=0;i<temp.size();i++)
    {
        bool check=true;
        for(int j=1;j<temp[0].size();j++)
        {
            if(temp[i][j]!=temp[i][j-1])
            {
                check=false;
                break;
            }

        }
        if(check!=false)
        res++;
    }
    return res;
}
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int result=0;
        vector<vector<int>>temp=matrix;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    flip(j,temp,i);
                }
            }
           result=max(result, count(temp));
            temp=matrix;
        }
        return result;
    }
};