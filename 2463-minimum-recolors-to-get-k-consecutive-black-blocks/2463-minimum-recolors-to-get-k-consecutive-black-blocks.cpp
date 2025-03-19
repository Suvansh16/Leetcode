class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=0;
        int j=k-1;
        int maxb=0;
        for(int i=0;i<k;i++)
        {
            if(blocks[i]=='B')
            maxb++;
        }
        int count=maxb;
        while(j<blocks.length())
        {
            if(blocks[i]=='B')
            {
                count--;
            }

            i++;
            j++;
            if(j<blocks.length())
            {
                if(blocks[j]=='B')
                count++;
                maxb=max(maxb,count);
            }
            else
            continue;

        }
        if(k-maxb<=0)
        return 0;
        return k-maxb;
    }
};