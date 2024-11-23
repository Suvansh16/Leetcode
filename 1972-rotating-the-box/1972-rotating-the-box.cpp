class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n=box[0].size();
        vector<vector<char>>temp(n,vector<char>(m,'.'));
        
        for(int i=0;i<m;i++)
        {
            for(int j=n-1;j>=0;j--)
            {
               
                if(box[i][j]=='#')
                {
                    box[i][j]='.';
                    int t=j;
                    while(t<n && box[i][t]!='*' && box[i][t]!='#')
                    {
                        t++;
                    }
                    box[i][t-1]='#';
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
             temp[j][m - i - 1] = box[i][j];
            }

        }
        return temp;
    }
};