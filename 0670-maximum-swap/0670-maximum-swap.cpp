class Solution {
public:
    int maximumSwap(int num) {
        vector<int>temp(10,-1);
        string a=to_string(num);
        int n=a.length();
        for(int i=0;i<n;i++)
        {
            int val=a[i]-'0';
            temp[val]=i;
        }
        for(int i=0;i<n;i++)
        {
            int val=a[i]-'0';
            int maxi=val;
            int idx=i;
            int l=-1;
            for(int i=maxi+1;i<10;i++)
            {
                if(i>maxi && temp[i]>idx)
                {
                    maxi=i;
                   l=temp[i];
                }
            }
            if(maxi!=val)
            {
                swap(a[idx],a[l]);
                break;
            }
        }
        return stoi(a);
    }
};