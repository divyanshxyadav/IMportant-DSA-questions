class Solution {
public:
void dfs(vector<vector<char>>& board,vector<vector<int>>&vis,int i,int j){
    vis[i][j]=1;
    int dr[4]={0,0,-1,1};
    int dc[4]={-1,1,0,0};
    for(int k=0;k<4;k++){
        int row=i+dr[k];
        int col=j+dc[k];
        if(row>=0 && row<board.size() && col>=0 && col<board[0].size() &&
        !vis[row][col] && board[row][col]=='O'){
            dfs(board,vis,row,col);
        }
    }
}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(!vis[0][i] && board[0][i]=='O'){
                dfs(board,vis,0,i);
            }
            if(!vis[n-1][i] && board[n-1][i]=='O'){
                dfs(board,vis,n-1,i);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(board,vis,i,0);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(board,vis,i,m-1);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O')
                board[i][j]='X';
            }
        }
    }
};