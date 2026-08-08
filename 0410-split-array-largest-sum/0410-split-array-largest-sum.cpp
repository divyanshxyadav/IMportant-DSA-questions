class Solution {
public:
int countk(vector<int>& nums, int k,long long m){
    int numberk=1;
    long long cap=0;
    for(int i=0;i<nums.size();i++){
        if(cap+nums[i]<=m){
            cap+=nums[i];
        }
        else{
            numberk++;
            cap=nums[i];
        }
    }
    return numberk;
}
    int splitArray(vector<int>& nums, int k) {
        long long l=*max_element(nums.begin(),nums.end());
        long long r=accumulate(nums.begin(),nums.end(),0LL);
        long long ans=LLONG_MAX;
        while(l<=r){
            long long m=l+(r-l)/2;
            if(countk(nums,k,m)<=k){
                ans=min(ans,m);
                r=m-1;
           
            }
            else
            l=m+1;
        }
        return ans;
    }
};