class DSU{
    public:
    vector<int> parent,size;
    DSU(int n){
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        size.resize(n,1);
    }
    int find_parent(int x){
        if(parent[x]!=x)
            parent[x]=find_parent(parent[x]);
        return parent[x];
    }
    bool do_union(int u, int v){
        int pu=find_parent(u), pv=find_parent(v);
        if(pu==pv)
        return false;
        if(size[pu]>=size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        return true;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), ans=0;
        DSU dsu(n);
        multimap<int,pair<int,int>> edge;
        for(int i=0; i<n ;i++){
            for(int j=i+1; j<n; j++){
                int dis = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edge.insert({dis,{i,j}});
            }
        }
        for(auto itr: edge){
            auto [i,j] = itr.second;
            if(dsu.do_union(i,j))
            ans+=itr.first;
        }
        return ans;
    }
};
