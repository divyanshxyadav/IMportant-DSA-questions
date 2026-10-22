class Solution {
public:
    class DisjointSet {
    public:
        vector<int> size, parent;

        DisjointSet(int n) {
            size.resize(n + 1, 1);
            parent.resize(n + 1);

            for (int i = 0; i <= n; i++)
                parent[i] = i;
        }

        int findUPar(int node) {
            if (parent[node] == node)
                return node;
            else
                return parent[node] = findUPar(parent[node]);
        }

        void unionBySize(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if (ulp_u == ulp_v) return;

            else if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };
    bool isValid(int row,int col,int n){
        return (row>=0 && row<n && col>=0 && col<n);
    }

    int largestIsland(vector<vector<int>>& grid) {
int n=grid.size();
DisjointSet ds(n*n);
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(grid[i][j]==0)continue;
       int dr[]={-1,0,1,0};
       int dc[]={0,-1,0,1};
       for(int ind=0;ind<4;ind++){
        int adjr=i+dr[ind];
        int adjc=j+dc[ind];
    if(isValid(adjr,adjc,n) && grid[adjr][adjc]==1){
        int convnode=i*n + j;
        int adjconvnode=adjr*n + adjc;
        ds.unionBySize(convnode,adjconvnode);
    }
       }
}
}
int mx=0;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(grid[i][j]==1)continue;
         int dr[]={-1,0,1,0};
       int dc[]={0,-1,0,1};
       set<int>component;
       for(int ind=0;ind<4;ind++){
        int adjr=i+dr[ind];
        int adjc=j+dc[ind];
        if(isValid(adjr,adjc,n)){
            if(grid[adjr][adjc]==1)
            component.insert(ds.findUPar(adjr*n + adjc));
        }
       }
int size=0;
for(auto it:component){
    size+=ds.size[it];
}
mx=max(mx,size+1);
    }
}
for(int i=0;i<n*n;i++){
    mx=max(mx,ds.size[i]);
}
return mx;
    }
};