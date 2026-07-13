class Solution {
public:
int m,n,result=0,nonObs=0;
vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
void backtrack(vector<vector<int>>& grid,int i,int j,int count){
    if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==-1){
        return;
    }
    if(grid[i][j]==2){
        if(count==nonObs)
        result++;
        return;
    }
    grid[i][j]=-1;
    for(auto d:dir){
        int newi=i+d[0];
        int newj=j+d[1];
     backtrack(grid,newi,newj,count+1);
    }
grid[i][j]=0;
}
    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int stx,sty;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    nonObs++;
                }
                if(grid[i][j]==1){
                    stx=i;
                    sty=j;
                }
            }
        }
        nonObs++;
        int count=0;
        backtrack(grid,stx,sty,count);
        return result;
    }
};