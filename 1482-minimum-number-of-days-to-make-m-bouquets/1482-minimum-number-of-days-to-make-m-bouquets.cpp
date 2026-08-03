class Solution {
public:
bool possible(int mi,vector<int>&bloomDay,int k,int m){
    int cnt=0;
    int val=0;
for(int i=0;i<bloomDay.size();i++){
if(bloomDay[i]<=mi){
    cnt++;
}
else{
val+=cnt/k;
cnt=0;
}
}
val += cnt / k;
if(val>=m){
    return true;
}
else
return false;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size())
    return -1;
    auto p=minmax_element(bloomDay.begin(),bloomDay.end());
    int l=*p.first;
    int r=*p.second;
    int ans=INT_MAX;
        while(l<=r){
            int mi=l+(r-l)/2;
            if(possible(mi,bloomDay,k,m)){
ans=min(ans,mi);
r=mi-1;
            }
            else 
            l=mi+1;
        }
        return ans;
    }
};