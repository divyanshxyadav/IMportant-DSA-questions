class Solution {
public:
void solve(int idx,int target,vector<vector<int>>&ans,vector<int>&temp,vector<int>&candidates){
if( idx==candidates.size()){
if(target==0){
    ans.push_back(temp);
} return;
}
if(candidates[idx]<=target){
    temp.push_back(candidates[idx]);
    solve(idx,target-candidates[idx],ans,temp,candidates);
    temp.pop_back();
}
 solve(idx+1,target,ans,temp,candidates);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
solve(0,target,ans,temp,candidates);
return ans;
    }
};