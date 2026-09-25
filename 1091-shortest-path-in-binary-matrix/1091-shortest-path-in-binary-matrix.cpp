class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       int n=grid.size();
       queue<pair<int,pair<int,int>>>q;
       if(n==1 && grid[0][0]==0)return 1;
if(grid[0][0]!=0 || grid[n-1][n-1]!=0)
return -1;
       vector<vector<int>>dis(n,vector<int>(n,1e9));
       dis[0][0]=0;
       q.push({1,{0,0}});
       int dr[]={-1,-1,-1,0,0,1,1,1};
       int dc[]={-1,0,1,-1,1,-1,0,1};
       while(!q.empty()){
        auto it =q.front();
        q.pop();
        int dist=it.first;
        int r=it.second.first;
        int c=it.second.second;
        for(int i=0;i<8;i++){
            int row=r+dr[i];
            int col=c+dc[i];

            if(row>=0 && row<n && col>=0 && col<n && grid[row][col]==0 && dis[row][col]>dist+1){
                dis[row][col]=1+dist;
                q.push({1+dist,{row,col}});
if(row==n-1 && col==n-1)return dist+1;
            }
        }
       }
       return -1;
    }
};