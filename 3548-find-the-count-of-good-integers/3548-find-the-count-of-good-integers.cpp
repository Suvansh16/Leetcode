class Solution {
public:


    long long countGoodIntegers(int n, int k) {
        int d=(n+1)/2;
        long long start=pow(10,d-1);
        long long end=pow(10,d)-1;
        unordered_set< string >st;
        vector<long long>factorial(11,1);
    for(int i=1;i<11;i++)
    {
    factorial[i]=factorial[i-1]*i;
    }
        for(long long i=start;i<=end;i++)
        {
            string left=to_string(i);
            string full="";
            string right;
            if(n%2==0)
            right=left;
            else
            right=left.substr(0,left.size()-1);
            reverse(right.begin(),right.end());
            full=left+right;

            long long t=stoll(full);
            if(t%k!=0)
            continue;
            sort(full.begin(),full.end());
            st.insert(full);

        }
        long long result=0;
        for(const string  &i:st)
        {
            vector<int>count(10,0);
            for(const char &t:i)
            {
                count[t-'0']++;
            }
            int totaldigits=i.length();
            int totalnonzerodigits=i.size()-count[0];
            int zero=count[0];
            long long perm=totalnonzerodigits*factorial[totaldigits-1];
            for(int i=0;i<10;i++)
            {
                perm/=factorial[count[i]];
            }
            result+=perm;
        }
        return result;

    }
};