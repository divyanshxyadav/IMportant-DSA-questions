class Solution {
public:
void solve(vector<int>&temp,vector<vector<int>>&ans,int target,vector<int>& candidates,int idx){
    if(target<0)
    return;

if(target==0){
    ans.push_back(temp);return;
}


for(int i=idx;i<candidates.size();i++){
    if(i>idx && candidates[i]==candidates[i-1])
    continue;
    temp.push_back(candidates[i]);
    solve(temp,ans,target-candidates[i],candidates,i+1);
    temp.pop_back();
}

}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        vector<vector<int>>ans;
        solve(temp,ans,target,candidates,0);
        return ans;
    }
};