class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0;
        long long sum2=0;
        int count1=0;
        int count2=0;
        for(int i:nums1)
        {
            sum1+=i;
            if(i==0)
            count1++;

        }
        for(int i:nums2)
        {
            sum2+=i;
            if(i==0)
            count2++;
        }
        if(sum1>sum2)
        {
            if(count2==0)
            return -1;
            if(sum1-sum2>=count2)
            return sum1+count1;
            else if(sum1-sum2<count2)
            {
                if(count1==0)
                return -1;
                int diff=sum1-sum2;
                return sum1+max(count2-diff,count1);
            }
        }
        else if(sum2>sum1){
            if(count1==0)
            return -1;
            if(sum2-sum1>=count1)
            return sum2+count2;
            else if(sum2-sum1<count1)
            {
                if(count2==0)
                return -1;
                int diff=sum2-sum1;
                return sum2+max(count1-diff,count2);
            }
        }
        else
        {
            if((count1!=0 && count2==0 )|| (count1==0 && count2!=0))
            return -1;
            return sum1+max(count1,count2);
        }
        return -1;
    }
};