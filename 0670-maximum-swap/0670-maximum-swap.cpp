class Solution {
public:
    int maximumSwap(int num) {
        string a=to_string(num);
        int n=a.length();
        vector<int>maxright(n,-1);
        maxright[n-1]=n-1;
        for(int i=n-2;i>=0;i--)
        {
            int val=a[i]-'0';
            int rightval=a[maxright[i+1]]-'0';
            maxright[i]=(val>rightval?i:maxright[i+1]);
        }
        for(int i=0;i<n;i++)
        {
            if(i!=maxright[i] && a[i]!=a[maxright[i]]){
            swap(a[i],a[maxright[i]]);
            break;
            }
        }
        return stoi(a);
    }
};