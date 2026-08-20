class Solution {
public:
int solve(vector<int>& nums,int i,vector<int>&dp){
    int n=nums.size();

    if( i==n-1) return 0;
    if(dp[i]!=-1)return dp[i];
    int ans=1e8;
    for(int j=i+1;j<=min(n-1,i+nums[i]);j++){
        ans=min(ans,1+solve(nums,j,dp));
    }
    return dp[i]=ans;
}
    int jump(vector<int>& nums) {
        int n=nums.size();
       vector<int>dp(n,-1);
      return solve(nums,0,dp);
    }
};