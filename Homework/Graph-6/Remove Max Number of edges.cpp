class DSU{
    vector<int> size;
    vector<int> parent;
    public:
    DSU(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find_parent(int i){
        int x = parent[i];
        while(parent[x]!=x){
            x = parent[x];
        }
        return parent[i]=x;
    }
    bool union_nodes(int i,int j){
        int i_parent = find_parent(i);
        int j_parent = find_parent(j);
        if(i_parent==j_parent) return false;
        if(size[i_parent]<size[j_parent]){
            parent[i_parent] = j_parent;
            size[j_parent]+=size[i_parent];
        }else{
            parent[j_parent] = i_parent;
            size[i_parent]+=size[j_parent];
        }
        return true;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU A(n+1);
        DSU B(n+1);
        int edges_req = 0; 
        int m = edges.size();
        int n1 =1,n2 = 1;
        for(int i=0;i<m;i++){
            if(edges[i][0]==3){
                if(n1<n && A.union_nodes(edges[i][1],edges[i][2])){ 
                    n1++;
                    edges_req++;   
                }
                if(n2<n && B.union_nodes(edges[i][1],edges[i][2])){
                    n2++;
                }
            }
        }
        for(int i=0;i<m;i++){
            if(n1<n && edges[i][0]==1 && A.union_nodes(edges[i][1],edges[i][2])){
                edges_req++;
                n1++;
            }
            else if(n2<n && edges[i][0]==2 && B.union_nodes(edges[i][1],edges[i][2])){
                edges_req++;
                n2++;
            }
        }
        bool alice = false,bob = false;
        for(int i=1;i<=n;i++){
            if(A.find_parent(i)==i){
                if(alice)
                 return -1;
                alice = true;
            }
            if(B.find_parent(i)==i){
                if(bob) 
                return -1;
                bob = true;
            }
        }
        return m-edges_req;
    }
};
