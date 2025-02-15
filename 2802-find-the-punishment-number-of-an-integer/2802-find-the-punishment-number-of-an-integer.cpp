class Solution {
public:
bool canPartition(string sqr,int target,int sum)
{
    if(sum==target && sqr.empty())
    return true;
    if(sum>target)
    return false;
    for(int i=0;i<sqr.length();i++)
    {
        string left=sqr.substr(0,i+1);
        string right=sqr.substr(i+1);
        if(canPartition(right,target,sum+stoi(left)))
        return true;
    }
    return false;
}
    int punishmentNumber(int n) {
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            int sqr=i*i;
            if(canPartition(to_string(sqr),i,0))
            sum+=sqr;
        }
        return sum;
    }
};