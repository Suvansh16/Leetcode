class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    // Find with path compression
    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    // Union by rank
    void Union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;

        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parent.resize(n);
        rank.resize(n, 0);

        // Initialize the parent array
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        // Union the connected nodes
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1 && find(i) != find(j)) {
                    Union(i, j);
                }
            }
        }

        // Count the number of unique sets
        unordered_set<int> uniqueParents;
        for (int i = 0; i < n; ++i) {
            uniqueParents.insert(find(i));  // Use find(i) to ensure the correct root
        }

        return uniqueParents.size();
    }
};
