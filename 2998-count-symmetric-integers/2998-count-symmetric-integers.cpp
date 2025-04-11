class Solution {
public:
int  sum_of(int n)
{
    int sum=0;
    while(n)
    {
        int k=n%10;
        sum+=k;
         n=n/10;
    }
    return sum;
}
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++)
        {
            string a=to_string(i);
            int l=a.length();
            if(l%2==0)
            {
                int s=l/2;
                string m=a.substr(0,s);
                string n=a.substr(s);
                int r=sum_of(stoi(m));
                int f=sum_of(stoi(n));
                if(r==f)
                count++;
            }

        }
        return count;
    }
};