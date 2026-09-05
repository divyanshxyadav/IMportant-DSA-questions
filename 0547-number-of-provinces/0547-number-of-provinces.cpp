class Solution {
public:
void dfs(vector<int>&vis,int node,vector<vector<int>>&ls){
    vis[node]=1;
    for(auto it:ls[node]){
        if(!vis[it]){
            dfs(vis,it,ls);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
     vector<vector<int>>ls(n);
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1 && i!=j){
                ls[i].push_back(j);
                ls[j].push_back(i);
            }
        }
     }
     vector<int>vis(n);
     int cnt=0;
     for(int i=0;i<n;i++){
        if(!vis[i]){
            cnt++;
            dfs(vis,i,ls);
        }
     }   
return cnt;
    }
};