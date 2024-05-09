
class DSU {
    vector<int> par;
    vector<int> rnk;
public:
    DSU(int n, vector<int>& rw) {
        par.resize(n);
        rnk.resize(n);
        for(int i = 0; i < n; i += 2) {
            par[rw[i]] = rw[i];
            par[rw[i+1]] = rw[i];
            rnk[rw[i]] = 2;
            rnk[rw[i+1]] = 2;
        }
    }
    int find_parent(int i) {
        int x = par[i];
        while(par[x] != x) {
            x = par[x];
        }
        return par[i] = x;
    }
    bool join(int i, int j) {
        int pi = find_parent(i);
        int pj = find_parent(j);
        if(pi == pj) return false;
        if(rnk[pi] <= rnk[pj]) {
            par[pi] = pj;
            rnk[pj] += rnk[pi];
        } else {
            par[pj] = pi;
            rnk[pi] += rnk[pj];
        }
        return true;
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        DSU dsu(n, row);
        int swaps = 0;
        for(int i = 0; i < n; i += 2) {
            if(dsu.join(i, i+1)) swaps++;
        }
        return swaps;
    }
};
