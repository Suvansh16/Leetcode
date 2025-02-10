class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& v) {
        sort(v.begin(), v.end());
        unordered_map<int, long long> dp;
        unordered_set<int> s(v.begin(), v.end());
        long long mod = 1e9 + 7;
        long long ans = 0;

        for (int i = 0; i < v.size(); i++) {
            dp[v[i]] = 1; // Each element can be a single-node tree
            for (int j = 0; j < i; j++) {
                if (v[i] % v[j] == 0) { // v[j] is a factor
                    int x = v[i] / v[j];
                    if (s.count(x)) { // Ensure the other factor is present in the array
                        dp[v[i]] = (dp[v[i]] + (dp[v[j]] * dp[x])) ;
                    }
                }
            }
            ans = (ans + dp[v[i]]) % mod;
        }
        return ans;
    }
};


// class Solution {
// public:
//     int numFactoredBinaryTrees(vector<int>& v) {
//         unordered_set<int>s;
//         sort(v.begin(),v.end());
//         for (auto it:v){
//             s.insert(it);
//         }
//         int op=0;
//         unordered_map<int,int>m;
//         int ans=0;
//         for (int i =0;i<v.size();i++){
//             for (int j=0;j<v.size();j++){
//                 int x= v[i]/v[j];
//                 int m=v[i]%v[j];
//                 if (m.find(v[i])!=m.end()) ans+=m[v[i]];
//                 if (m.find(v[j])!=m.end()) ans+=m[v[j]];
//                 if (s.find(x)!=s.end() && m==0) ans++;
//             }
//             op+=ans;
//             m[x]=ans;
//         }
//         return op+v.size();
//     }
// };