class Solution {
public:
bool dfs(int i,vector<vector<int>>& graph,vector<int>&pathVis,vector<int>&vis,set<int>&res){
    vis[i]=1;
    pathVis[i]=1;
    for(auto it:graph[i]){
        if(!vis[it]){
         if(dfs(it,graph,pathVis,vis,res))return true;
        }
        else if(pathVis[it])
        return true;
    }
    pathVis[i]=0;
    res.insert(i);
    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n=graph.size();
vector<int> pathVis(n, 0);
vector<int> vis(n, 0);
set<int>res;
for(int i=0;i<n;i++){
    if(!vis[i])
    dfs(i,graph,pathVis,vis,res);
}
vector<int>ans(res.begin(),res.end());
return ans;
    }
};