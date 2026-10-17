class Solution {
public:
class DisjointSet{
    public:
    vector<int>rank,parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        parent[i]=i;
    }
    int findUPar(int node){
        if(parent[node]==node)
        return node;
        else
        return parent[node]=findUPar(parent[node]);
    }
    void unionbyrank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v)return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
else{
    parent[ulp_v]=ulp_u;
    rank[ulp_u]++;
}
    }
};
    int makeConnected(int n, vector<vector<int>>& connections) {
    DisjointSet ds(n);
    int cntExtra=0;
    for(auto it:connections){
        int u=it[0];
        int v=it[1];
        if(ds.findUPar(u)==ds.findUPar(v))
        cntExtra++;
        else
        ds.unionbyrank(u,v);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(ds.parent[i]==i)
        ans++;
    }    

    if(cntExtra>=ans-1)return ans-1;
    else return -1;
    }
};