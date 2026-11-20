class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(auto it:words){
            mp[it]++;
        }
        vector<pair<string,int>>arr;
for(auto it:mp){
    arr.push_back({it.first,it.second});
}
auto lambda=[](pair<string,int>p1,pair<string,int>p2){
    if(p1.second==p2.second){
        return p1.first<p2.first;
    }

return p1.second>p2.second;
};
sort(arr.begin(),arr.end(),lambda);
vector<string>ans(k);
int i=0;
while(i<k){
    ans[i]=arr[i].first;
    i++;
}
return ans;
    }
};