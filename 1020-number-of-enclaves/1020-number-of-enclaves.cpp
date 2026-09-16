class Solution {
public:
void dfs(vector<vector<int>>& grid,vector<vector<int>>&vis,int i,int j){
    vis[i][j]=1;
    int dr[4]={0,0,-1,1};
    int dc[4]={-1,1,0,0};
    for(int k=0;k<4;k++){
        int row=i+dr[k];
        int col=j+dc[k];
        if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size() &&
        !vis[row][col] && grid[row][col]==1){
            dfs(grid,vis,row,col);
        }
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(!vis[0][i] && grid[0][i]==1){
                dfs(grid,vis,0,i);
            }
            if(!vis[n-1][i] && grid[n-1][i]==1){
                dfs(grid,vis,n-1,i);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(grid,vis,i,0);
            }
            if(!vis[i][m-1] && grid[i][m-1]==1){
                dfs(grid,vis,i,m-1);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1)
                cnt++;
            }
        }  
        return cnt; 
    }
};