class Solution {
public: 
int t[1001];
int m=1e9+7;
int solve(int n)
{
    if(n==1 || n==2)
    return n;
    if(n==3)
    return 5;
    if(t[n]!=-1)
    return t[n];
    return t[n]=(2*solve(n-1)%m+solve(n-3)%m)%m;

}
    int numTilings(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
    }
};