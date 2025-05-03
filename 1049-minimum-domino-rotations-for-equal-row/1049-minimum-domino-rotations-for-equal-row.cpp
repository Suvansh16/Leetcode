class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    vector<pair<int,int>>top_array(7);
    for(int i=0;i<7;i++)
    {
        top_array[i]={0,0};
    }
    vector<pair<int,int>>bottom_array(7);
    for(int i=0;i<7;i++)
    {
        bottom_array[i]={0,0};
    }
    for(int i=0;i<tops.size();i++)
    {
        int a=tops[i];
        int b=bottoms[i];
        if(a==b)
        {
            top_array[a].first++;
            bottom_array[a].first++;
        }
        else
        {
            top_array[b].first++;
            top_array[b].second++;
            top_array[a].first++;
            bottom_array[a].first++;
            bottom_array[a].second++;
            bottom_array[b].first++;
        }
    }


    for(int i=0;i<7;i++)
    {
        cout<<top_array[i].first<<" "<<top_array[i].second<<" ";
        cout<<bottom_array[i].first<<" "<<bottom_array[i].second<<" ";
        cout<<endl;

    }
    int mini=INT_MAX;
    for(int i=0;i<7;i++)
    {
        if(top_array[i].first==tops.size())
        {
            mini=min({mini,top_array[i].second,bottom_array[i].second});
        }
        

    }
    return mini==INT_MAX?-1:mini;
    }
};