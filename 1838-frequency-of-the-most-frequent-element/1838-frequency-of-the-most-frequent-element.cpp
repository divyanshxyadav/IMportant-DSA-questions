class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long left=0; long long sum=0;
        long long ans=1;
        for(long long right=0;right<nums.size();right++){
sum+=nums[right];
while((long long)nums[right]*(right-left+1)-sum>k){
    sum-=nums[left];
    left++;
}
ans=max(ans,right-left+1);
        }
        return ans;
    }
};