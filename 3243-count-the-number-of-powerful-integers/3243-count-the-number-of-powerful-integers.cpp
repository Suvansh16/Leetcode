class Solution {
public:
long long solve(string str,string s,int limit)
{
    if(str.length()<s.length())
    return 0;
    long long count=0;
    string trail=str.substr(str.length()-s.length());
    int remain=str.length()-s.length();
    for(int i=0;i<remain;i++)
    {
        int digit=str[i]-'0';
        if(digit<=limit)
        {
            count+=digit*pow(limit+1,remain-i-1);
            
        }
        else
        {
            count+=pow(limit+1,remain-i);
            return count;
        }
    }
    if(trail>=s)
    count+=1;
    return count;

}
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string startstr=to_string(start-1);
        string finishstr=to_string(finish);
        return solve(finishstr,s,limit)-solve(startstr,s,limit);
    }
};