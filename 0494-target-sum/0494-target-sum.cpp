class Solution {
public:
int solve(vector<int>& nums, int target,int idx,vector<unordered_map<int,int>>&dp){
    if(idx==0){
        int ways=0;
        if(nums[0]==target)
        ways++;
    if(-nums[0]==target)
        ways++;
        return ways;
    }
if(dp[idx].count(target))return dp[idx][target];
    int plus=solve(nums,target-nums[idx],idx-1,dp);
    int minus=solve(nums,target+nums[idx],idx-1,dp);
    return dp[idx][target]=plus+minus;

}
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int,int>>dp(nums.size());
        return solve(nums,target,nums.size()-1,dp);
    }
};