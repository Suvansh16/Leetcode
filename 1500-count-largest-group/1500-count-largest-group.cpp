class Solution {
public:
int sum(int t)
{
    int su=0;
    while(t)
    {
        int a=t%10;
        su+=a;
        t/=10;
    }
    return su;
}
    int countLargestGroup(int n) {
        unordered_map<int,int>map;
        for(int i=1;i<=n;i++)
        {
            int t=sum(i);
            map[t]++;
        }
        int maxi=0;
        int count=0;
        for(auto i:map)
        {
            if(i.second>maxi)
            {
                maxi=i.second;
                count=1;
            }
            if(i.second==maxi)
            count++;
            
        }
        return count-1;

    }
};