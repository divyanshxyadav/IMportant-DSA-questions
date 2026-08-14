class Solution {
public:
int solve(vector<vector<int>>& matrix,int idx,int i,vector<vector<int>>&dp){
   if(idx==matrix.size()-1)
   return matrix[idx][i];
   if(dp[idx][i]!=1e9)return dp[idx][i];
   int path2=1e9;
   int path3=1e9;
 int path1=matrix[idx][i]+solve(matrix,idx+1,i,dp);
 if(i<matrix.size()-1) path2=matrix[idx][i]+solve(matrix,idx+1,i+1,dp);
 if(i>0) path3=matrix[idx][i]+solve(matrix,idx+1,i-1,dp);
int hehe=min(path1,path2);
return dp[idx][i]=min(hehe,path3);
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        int idx=0;
        int ans=INT_MAX;
        for(int i=0;i<matrix.size();i++){
ans=min(ans,solve(matrix,idx,i,dp));
        }
        return ans;
    }
};