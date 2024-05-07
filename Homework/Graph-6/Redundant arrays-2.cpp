class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        iota(parent.begin(),parent.end(),0);
    }
    
    int findParent(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    
    bool unionNodes(int u, int v) {
        int uu = findParent(u);
        int vv = findParent(v);
        if(uu == vv) return false;
        if(rank[uu] > rank[vv])
            parent[vv] = parent[uu];
        else if(rank[uu] < rank[vv])
            parent[uu] = parent[vv];
        else {
            parent[uu] = parent[vv];
            rank[vv]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int maxVal = INT_MIN;
        for(auto edge : edges)
            maxVal = max({maxVal, edge[0], edge[1]});
        int idx1 = -1, idx2 = -1, n = edges.size();
        vector<int> indices(maxVal, -1);
        for(int i = 0; i < n; i++) {
            if(indices[edges[i][1] - 1] == -1)
                indices[edges[i][1] - 1] = i;
            else {
                idx1 = i;
                idx2 = indices[edges[i][1] - 1];
            }
        }
        if(idx1 == -1 && idx2 == -1) {
            DSU dsu(maxVal);
            for(int i = 0; i < n; i++) {
                if(!dsu.unionNodes(edges[i][0] - 1, edges[i][1] - 1))
                    return edges[i];
            }
        }
        DSU dsu(maxVal);
        for(int i = 0; i < n; i++) {
            if(i == idx1)
                continue;
            if(!dsu.unionNodes(edges[i][0] - 1, edges[i][1] - 1))
                return edges[idx2];
        }
        return edges[idx1];
    }
};
