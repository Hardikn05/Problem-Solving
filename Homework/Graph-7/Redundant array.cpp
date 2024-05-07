class DSU{
    private:
    vector<int> size;
    vector<int> parent;
    public:
    DSU(int Nodes)
    {
        size.resize(Nodes,1);
        parent.resize(Nodes);
        for(int i=0;i<Nodes;i++)
        parent[i]=i;
    }

    int find(int node)
    {
        if(parent[node]==node)
         return node;

        return find(parent[node]);
    }

    bool unionNode(int u,int v)
    {
        int P_u = find(u);
        int P_v = find(v);

        if(P_u == P_v)
         return false;

        if(size[P_u]<=size[P_v])
        {
            parent[P_u] = P_v;
            size[P_u]+=size[P_v];
        }
        else
        {
            parent[P_v]=P_u;
            size[P_v]+=size[P_u];
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = edges.size();
        DSU dsu(n+1);
         for(int i=0;i<edges.size();i++)
         {
            int u = edges[i][0];
            int v = edges[i][1];

            if(!dsu.unionNode(u,v))
            {
                return {u,v};
            }
         }
         return {};
    }
};
