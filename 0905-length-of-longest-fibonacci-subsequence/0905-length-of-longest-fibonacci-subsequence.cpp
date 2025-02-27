class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int maxi=2;
        unordered_set<int>st(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-2;i++)
        {
            for(int j=i+1;j<arr.size()-1;j++)
            {
                int count=2,first=arr[i],second=arr[j];
                while(st.count(first+second))
                {
                    int sum=first+second;
                    first=second;
                    second=sum;
                    count++;
                }
                maxi=max(maxi,count);
            }
        }
        return maxi>2?maxi:0;
    }
};