class Solution {
public:
bool check(vector<int>& position, int mi,int m){
    long long t=1;
    long long i=0,j=1;
    while(j<position.size()){
        if((position[j]-position[i])>=mi){
            t++;
            i=j;
        }
        j++;
    }
    if(t>=m)
    return true;
    else return false;
}
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        long long l=1;
        long long r=*max_element(position.begin(),position.end())-*min_element(position.begin(),position.end());
        long long ans=INT_MIN;
        while(l<=r){
            long long mi=l+(r-l)/2;
            if(check(position,mi,m)){
                ans=max(ans,mi);
                l=mi+1;
            }
            else
            r=mi-1;
        }
        return ans;
    }
};