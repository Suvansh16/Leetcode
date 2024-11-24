class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int count=0;
        int mini=INT_MAX;
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
               
                if(matrix[i][j]<0){
                    count++;
                sum+=(-1*matrix[i][j]);
                mini=min(mini,-1*matrix[i][j]);
                }
                else{
                sum+=matrix[i][j];
                  mini=min(mini,matrix[i][j]);
                }
            }
        }
        if(count%2==0)
        return sum;
        return sum-2*mini;
    }
};