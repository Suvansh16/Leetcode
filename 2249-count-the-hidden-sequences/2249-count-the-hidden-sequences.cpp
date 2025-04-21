class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long prefix=0,minval=0,maxval=0;
        for(int diff:differences)
        {
            prefix+=diff;
            minval=min(minval,prefix);
            maxval=max(maxval,prefix);
        }
        //l<=minval+a
        //u>=maxval+a
        //a>=l-minval
        //a<=u-maxval
        //a=[l-minval,u-maxval]
        //range==(u-maxval + l-minval +1)

       long low = lower - minval;
        long high = upper - maxval;
         if (low > high)
            return 0;
        return high - low + 1;
    }
};