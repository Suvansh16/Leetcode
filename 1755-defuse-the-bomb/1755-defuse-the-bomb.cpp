class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>ans;
        if(k==0)
        {
            for(int i=0;i<n;i++)
            ans.push_back(0);
        }
        else if(k>0)
        {
            for(int i=0;i<n;i++)
            {
                int sum=0;
                for(int j=i+1;j<=i+k;j++)
                {
                   
                       
                         sum+=code[j%n];
                  
                   
                }
                ans.push_back(sum);
            }
        }
        else 
        {
            for(int i=0;i<n;i++)
            {
                int sum=0;
                int j=i-1;
                int count=-1*k;
                while(count--)
                {
                    if(j<0)
                    sum+=code[j+n];
                    else
                    sum+=code[j];
                    j--;
                }
                ans.push_back(sum);
            }
        }
        return ans;
    }
};