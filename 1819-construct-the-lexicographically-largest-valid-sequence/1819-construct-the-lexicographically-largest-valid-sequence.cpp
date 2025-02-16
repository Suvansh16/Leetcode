class Solution {
public:
bool backtrack(vector<int>&result,vector<bool>&used,int n,int index)
{
    while(index<result.size() && result[index]!=0)
    {
        index++;
    }
    if(index == result.size())
    return true;

    for(int i=n;i>=1;i--)
    {
        if(used[i]==true)
        continue;

        if(i==1)
        {
            used[i]=true;
            result[index]=1;
            if(backtrack(result,used,n,index+1))
            return true;

            used[i]=false;
            result[index]=0;

        }
        else if(index+i<result.size() && result[index+i]==0)
        {
            result[index]=i;
            result[index+i]=i;
            used[i]=true;
            if(backtrack(result,used,n,index+1))
            return true;
            result[index]=0;
            result[index+i]=0;
            used[i]=false;
        }
    }
    return false;
}
    vector<int> constructDistancedSequence(int n) {
        vector<int>result((2*n)-1,0);
        vector<bool>used(n+1,false);
        backtrack(result,used,n,0);
        return result;
    }
};