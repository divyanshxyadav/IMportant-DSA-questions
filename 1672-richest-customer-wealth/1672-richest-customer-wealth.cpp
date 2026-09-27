class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=0;
        for(auto t:accounts){
            int sum=0;
            for(auto it:t){
                sum+=it;
            }
            ans=max(ans,sum);
        }return ans;
    }
};