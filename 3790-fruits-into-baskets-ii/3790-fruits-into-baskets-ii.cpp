class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<bool>t(baskets.size(),false);
        int count=0;
        for(int i=0;i<fruits.size();i++)
        {
            int a=fruits[i];
            bool m=false;
            for(int j=0;j<baskets.size();j++)
            {
                if(!t[j] && baskets[j]>=a)
                {
                    t[j]=true;
                    m=true;
                    break;

                }
            }
            if(m==false)
            count++;
        }
        return count;
    }
};