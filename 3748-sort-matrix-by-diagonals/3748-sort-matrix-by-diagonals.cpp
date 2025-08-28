class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int i=0,j=0;
        while(i<grid.size())
        {
            int new_i=i,new_j=j;
            vector<int>arr;
            while(new_i<grid.size())
            {
                arr.push_back(grid[new_i++][new_j++]);
               
            }
            sort(arr.rbegin(),arr.rend());
            new_i=i,new_j=j;
            int t=0;
            while(new_i<grid.size())
            {
                grid[new_i][new_j]=arr[t++];
                new_i++;
                new_j++;
            }
            i+=1;
        }
        i=0;
        j=1;
         while(j<grid[0].size())
        {
            int new_i=i,new_j=j;
            vector<int>arr;
            while(new_j<grid[0].size())
            {
                arr.push_back(grid[new_i][new_j]);
                new_i++;
                new_j++;
            }
            sort(arr.begin(),arr.end());
            new_i=i,new_j=j;
            int t=0;
            while(new_j<grid[0].size())
            {
                grid[new_i][new_j]=arr[t++];
                new_i++;
                new_j++;
            }
            j+=1;
        }
        return grid;
    }
};