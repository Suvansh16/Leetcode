class Solution {
public:
double t[101][101];
double solve(int pour,int row,int col)
{
    if(row<col || row<0 || col<0)
    return 0.00;

    if(row==0 && col == 0)
    return pour;
    if(t[row][col]!=-1.0)
    return t[row][col];

    double left=(solve(pour,row-1,col-1)-1)/2.0;
    double right=(solve(pour,row-1,col)-1)/2.0;
    if(left<0)
    left=0.0;


    if(right<0)
    right=0.0;

    double total=left+right;
    return t[row][col]=total;
}
    double champagneTower(int poured, int query_row, int query_glass) {
       for (int i = 0; i <= 100; ++i)
    for (int j = 0; j <= 100; ++j)
        t[i][j] = -1.0;

        return min(1.00,solve(poured,query_row,query_glass));

    }
};