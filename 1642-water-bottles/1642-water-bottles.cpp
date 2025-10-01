class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0;
        int remain=0;
        while(numBottles)
        {
            ans+=numBottles;
            remain+=(numBottles%numExchange);
            numBottles/=numExchange;
            
        }
        while(remain/numExchange>0){
        int t=(remain/numExchange);
        ans+=t;
        remain=t+(remain%numExchange);
        }
        return ans;
    }
};