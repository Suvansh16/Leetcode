class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans(boxes.length(),0);
        int n=boxes.length();
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            ans[i]=ans[i]+sum;
            if(boxes[i]=='1')
            count++;
            sum+=count;
        }
        sum=0;
        count=0;
        for(int i=n-1;i>=0;i--)
        {
            ans[i]+=sum;
            if(boxes[i]=='1')
            count++;
            sum+=count;
        }
        return ans;
    }
};