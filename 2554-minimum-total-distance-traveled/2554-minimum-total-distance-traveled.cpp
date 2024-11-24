class Solution {
public:
typedef long long ll;
ll solve(int robotpos,int factorypos,vector<int>&robot,vector<int>&positions,vector<vector<ll>>&t)
{
    if(robotpos>=robot.size())
    {
        return 0;
    }
    if(factorypos>=positions.size())
    {
        return 1e12;
    }
    if(t[robotpos][factorypos]!=-1)
    return t[robotpos][factorypos];
    ll take=abs(positions[factorypos]-robot[robotpos])+solve(robotpos+1,factorypos+1,robot,positions,t);
    ll nottake=solve(robotpos,factorypos+1,robot,positions,t);
    
    return t[robotpos][factorypos]=min(take,nottake);
}
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int m=robot.size();
        int n=factory.size();
        //sort both robot and factory
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        //simplify factory
        vector<int>positions;
        for(int i=0;i<n;i++)
        {
            int a=factory[i][1];
            while(a--)
            positions.push_back(factory[i][0]);
        }
        int s=positions.size();
        vector<vector<ll>>t(m+1,vector<ll>(s+1,-1));
        return solve(0,0,robot,positions,t);

    }
};