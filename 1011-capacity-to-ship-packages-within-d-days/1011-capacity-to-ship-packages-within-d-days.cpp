class Solution {
public:
    bool solve(vector<int>& weights, int m, int days) {
        int i = 0;
        int sum = 0;
        int d = 1;

        while (i < weights.size()) {
            if (sum + weights[i] <= m) {
                sum += weights[i];
            } else {
                d++;
                sum = weights[i];
            }
            i++;
        }

        return d <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int r=accumulate(weights.begin(),weights.end(),0);
        int l=*max_element(weights.begin(),weights.end());
        int ans=INT_MAX;
        while(l<=r){
            int m=l+(r-l)/2;
            if(solve(weights,m,days)){
ans=min(ans,m);
r=m-1;
}
else
l=m+1;
}
        return ans;
    }
};