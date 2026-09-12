class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        int vis[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
if(grid[i][j]==2){
    q.push({{i,j},0});
    vis[i][j]=2;
}
else{
    vis[i][j]=0;
}}}
int tm=0;
while(!q.empty()){
    int r=q.front().first.first;
    int c=q.front().first.second;
    int t=q.front().second;
    q.pop();
tm=max(tm,t);
int drow[4]={-1,0,1,0};
int dcol[4]={0,1,0,-1};
for(int i=0;i<4;i++){
    int row=r+drow[i];
    int col=c+dcol[i];
    if(row>=0 && row<n && col>=0 && col<m && vis[row][col]==0 && grid[row][col]==1){
        q.push({{row,col},t+1});
vis[row][col]=2;
    }
}
}
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(vis[i][j]!=2 && grid[i][j]==1)
        return -1;
    }
}
return tm;
    }
};