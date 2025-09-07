class Solution {
public:

    bool solve(int start, vector<bool>& visited, vector<bool>& inrecursion,
               unordered_map<int, vector<int>>& graph, vector<int>& output) 
    {
        if (inrecursion[start]) return false;   // cycle
        if (visited[start]) return true;

        visited[start] = true;
        inrecursion[start] = true;

        for (int i : graph[start]) {
            if (!solve(i, visited, inrecursion, graph, output))
                return false;
        }

        inrecursion[start] = false;
        output.push_back(start);  // push AFTER recursion for topo order
        return true;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& r, vector<vector<int>>& c) {
        unordered_map<int, vector<int>> map1, map2;

        // Fix edge direction: a -> b (a before b)
        for (auto& i : r) map1[i[0]].push_back(i[1]);
        for (auto& i : c) map2[i[0]].push_back(i[1]);

        vector<bool> visited(k+1, false);
        vector<int> seq1;

        // Topo sort for rows
        for (int i = 1; i <= k; i++) {
            if (visited[i]) continue;
            vector<bool> inrecursion(k+1, false);
            if (!solve(i, visited, inrecursion, map1, seq1))
                return {};
        }
        reverse(seq1.begin(), seq1.end());

        // Reset visited
        fill(visited.begin(), visited.end(), false);
        vector<int> seq2;

        // Topo sort for cols
        for (int i = 1; i <= k; i++) {
            if (visited[i]) continue;
            vector<bool> inrecursion(k+1, false);
            if (!solve(i, visited, inrecursion, map2, seq2))
                return {};
        }
        reverse(seq2.begin(), seq2.end());

        // Build result
        vector<vector<int>> result(k, vector<int>(k, 0));
        unordered_map<int, int> rowPos, colPos;

        for (int i = 0; i < k; i++) {
            rowPos[seq1[i]] = i;
            colPos[seq2[i]] = i;
        }

        for (int num = 1; num <= k; num++) {
            int r = rowPos[num];
            int cpos = colPos[num];
            result[r][cpos] = num;
        }

        return result;
    }
};
