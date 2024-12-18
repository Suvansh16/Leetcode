class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>ans;
        int i=prices.size()-1;
        stack<int>st;
       
        while(i>=0)
        {
            int top=prices[i];
            int ele=-1;
             while(!st.empty())
             {
                if(st.top()<=top)
                {
                    ele=st.top();
                    break;
                }
                st.pop();
             }
             if(ele==-1)
             {
                ans.push_back(top);
             }
             else
             ans.push_back(top-ele);
             st.push(top);
             i--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};