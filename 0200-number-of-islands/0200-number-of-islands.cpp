class Solution {
public:
void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>&vis){
vis[i][j]=1;
if(i>0){
    if(grid[i-1][j]=='1' && vis[i-1][j]==0)
    dfs(i-1,j,grid,vis);
    }
if(i<grid.size()-1){
    if(grid[i+1][j]=='1' && vis[i+1][j]==0)
    dfs(i+1,j,grid,vis);
    }
if(j>0){
    if(grid[i][j-1]=='1' && vis[i][j-1]==0)
    dfs(i,j-1,grid,vis);
    }
if(j<grid[0].size()-1){
    if(grid[i][j+1]=='1' && vis[i][j+1]==0)
    dfs(i,j+1,grid,vis);
    }
}
    int numIslands(vector<vector<char>>& grid){
      vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
int cnt=0;
for(int i=0;i<grid.size();i++){
    for(int j=0;j<grid[0].size();j++){
        if(grid[i][j]=='1' && vis[i][j]==0){
            cnt++;
            dfs(i,j,grid,vis);
        }
    }
}return cnt;
    }
};