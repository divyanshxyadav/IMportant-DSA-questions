class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
auto idx=max_element(piles.begin(),piles.end());
int l=1,r=piles[idx-piles.begin()],ans=INT_MAX;
while(l<=r){
    int m=(l+r)/2;
    long long ho=0;
    for(auto i:piles){
ho+=(i+m-1)/m;
    }
if(ho<=h){
    ans=min(ans,m);
    r=m-1;
}
else
l=m+1;
}
return ans;
    }
};