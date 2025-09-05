class Solution {
public:
int mod=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
       sort(arr.begin(),arr.end());
        unordered_map<int,long long >map;
        for(int i:arr)
        map[i]=1;
        int ans=0;
        for(int i=1;i<arr.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0)
                {
                    int sec=arr[i]/arr[j];
                    if(map.find(sec)!=map.end())
                    {
                        map[arr[i]]=(map[arr[i]]%mod+(map[arr[j]]%mod*map[sec]%mod)%mod)%mod;
                    }
                }
            }
        }
        for(auto i:map)
        ans=(ans%mod+i.second%mod)%mod;
        return ans;
    }
};