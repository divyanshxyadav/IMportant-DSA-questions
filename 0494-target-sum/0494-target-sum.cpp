class Solution {
public:
int solve(vector<int>& nums, int target,int idx){
    if(idx==0){
        int ways=0;
        if(nums[0]==target)
        ways++;
    if(-nums[0]==target)
        ways++;
        return ways;
    }
    int plus=solve(nums,target-nums[idx],idx-1);
    int minus=solve(nums,target+nums[idx],idx-1);
    return plus+minus;

}
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,nums.size()-1);
    }
};