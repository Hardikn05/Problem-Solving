#include <bits/stdc++.h>
using namespace std;
int m = 998244353;
vector<int> rndVec;
void generateRndVec()
{
    for (int i = 1; i < 300009; i++)
    {
        rndVec.push_back((rndVec[rndVec.size() - 1] * 2) % m);
    }
}
bool dfs(int nd, vector<vector<int>>& a, vector<int>& v, int& c1, int& c2)
{
    if (v[nd] == -1)
    {
        v[nd] = 1;
        c1++;
    }
    bool res = true;
    for (auto i : a[nd])
    {
        if (v[i] == -1)
        {
            v[i] = 1 - v[nd];
            if (v[i])
                c1++;
            else
                c2++;
            res &= dfs(i, a, v, c1, c2);
        }
        else if (v[i] == v[nd])
            res = false;
    }
    return res;
}
int main() {
    int x;
    cin >> x;
    rndVec.push_back(1);
    generateRndVec();
    while (x--)
    {
        int n, e;
        cin >> n >> e;
        vector<int> vis(n, -1);
        vector<vector<int>> adj(n);
        while (e--)
        {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
        long long ans = 1;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == -1)
            {
                int a = 0, b = 0;
                bool c = dfs(i, adj, vis, a, b);
                if (!c)
                {
                    ans = 0;
                    break;
                }
                int aa = rndVec[a] % m;
                int bb = rndVec[b] % m;
                ans = (ans * (aa + bb) % m) % m;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
