class Solution {
public:
bool search(int m,vector<int>&nums,int threshold){
int val=0;
for(auto p:nums){
    val+=(p+m-1)/m;
}
if(val<= threshold)
return true;
else
return false;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int ans=INT_MAX;
        auto it=max_element(nums.begin(),nums.end());
int r=*it;
while(l<=r){
int m=l+(r-l)/2;
if(search(m,nums,threshold)){
ans=min(ans,m);
    r=m-1;
}
else
l=m+1;
}
return ans;
    }
};