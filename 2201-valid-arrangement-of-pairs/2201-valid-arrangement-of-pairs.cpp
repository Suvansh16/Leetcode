#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> map;
        unordered_map<int, int> indegree, outdegree;
        
        // Build the graph and calculate in-degrees and out-degrees
        for (const vector<int>& v : pairs) {
            map[v[0]].push_back(v[1]);
            outdegree[v[0]]++;
            indegree[v[1]]++;
        }
        
        // Find the start node for the Eulerian path
        int startnode = -1;
        for (auto& entry : outdegree) {
            int node = entry.first;
            if (outdegree[node] - indegree[node] == 1) {
                startnode = node;  // This node has one more outgoing edge than incoming
                break;
            }
        }

        // If no start node was found, we need to start from any node that has outgoing edges
        if (startnode == -1) {
            startnode = pairs[0][0];  // Take the first node as the start if no specific start was found
        }

        // Perform DFS to find the Eulerian path
        vector<int> eulerpath;
        stack<int> st;
        st.push(startnode);
        
        while (!st.empty()) {
            int curr = st.top();
            
            // If there are outgoing edges, keep traversing
            if (!map[curr].empty()) {
                int ngbr = map[curr].back();  // Get the next neighbor
                st.push(ngbr);               // Push the neighbor to the stack
                map[curr].pop_back();        // Remove the edge from the graph
            } else {
                // No outgoing edges, add the node to the path and pop it from the stack
                eulerpath.push_back(curr);
                st.pop();
            }
        }

        // Reverse the path to get the correct order
        reverse(eulerpath.begin(), eulerpath.end());

        // Build the result from the Eulerian path
        vector<vector<int>> result;
        for (int i = 1; i < eulerpath.size(); i++) {
            result.push_back({eulerpath[i - 1], eulerpath[i]});
        }

        return result;
    }
};
