class Solution {
public:
const int mod=1e9+7;
int N;
int G;
int K;
long t[101][101];
long solve(int unique_ele,int unique_size)
{
    if(unique_size==G)
    {
        if(unique_ele==N)
        return 1;
        return 0;

    }
    if(t[unique_ele][unique_size]!=-1)
    return t[unique_ele][unique_size];
    long  play_new_song=0,replay=0;
    play_new_song=((N-unique_ele)*solve(unique_ele+1,unique_size+1))%mod;
    if(unique_ele>K)
     replay=((unique_ele-K)*solve(unique_ele,unique_size+1))%mod;
    return t[unique_ele][unique_size]=(play_new_song+replay)%mod;

}
    int numMusicPlaylists(int n, int goal, int k) {
        N=n;
        G=goal;
        K=k;
        memset(t,-1,sizeof(t));
        return solve(0,0);
    }
};