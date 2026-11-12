class Solution {
public:
void dfs(vector<int>&vis,int node,vector<vector<int>>&adj){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(vis,it,adj);
        }
    }
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       
        for(int i=edges.size()-1;i>=0;i--){
 vector<vector<int>>adj(edges.size()+1);
        
        for(int j=0;j<edges.size();j++){
            if(j==i)continue;
            int u=edges[j][0];
            int v=edges[j][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
int cnt=0;
vector<int>vis(adj.size(),0);
for(int k=1;k<adj.size();k++){
    if(vis[k]==0){
        cnt++;
        dfs(vis,k,adj);
    }
}
if(cnt==1)return edges[i];
        }
        return{};
    }
};