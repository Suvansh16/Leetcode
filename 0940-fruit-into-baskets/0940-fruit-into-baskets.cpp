class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>map;
        int maxi=0;
        int i=0,j=0;
        while(j<fruits.size())
        {
            if(map.size()==2 && map.find(fruits[j])==map.end()  )
            {
                int count=0;
                for(auto i:map)
                count+=i.second;
                maxi=max(count,maxi);
                while(map.size()!=1)
                {
                    map[fruits[i]]--;
                    if(map[fruits[i]]==0)
                    map.erase(fruits[i]);
                    i++;
                }
            }
            map[fruits[j]]++;
            j++;
        }
        int count=0;
        for(auto i:map)
        count+=i.second;
        maxi=max(maxi,count);
        return maxi;
    }
};