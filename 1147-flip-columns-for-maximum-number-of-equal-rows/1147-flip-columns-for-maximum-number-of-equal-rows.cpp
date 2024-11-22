class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int count=0;
        int n=matrix.size();
        int m=matrix[0].size();
        unordered_map<string,int>map;
        for(int i=0;i<n;i++)
        {
            int result=0;
            string temp="";
           int firstval=matrix[i][0];
            for(int j=0;j<m;j++)
            {
              temp.push_back(matrix[i][j]==firstval?'s':'b');
            }
            if(map.find(temp)!=map.end())
            continue;
            else
            {
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
           map[temp]=result;
            }
        }
        int maxi=0;
        for(auto &i:map)
        maxi=max(maxi,i.second);
        return maxi;
    }
};