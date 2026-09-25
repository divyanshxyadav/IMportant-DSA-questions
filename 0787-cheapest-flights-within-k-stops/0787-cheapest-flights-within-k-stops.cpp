class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e9);
dist[src]=0;
        int ans=INT_MAX;
        q.push({src,{0,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node=it.first;
            int wt=it.second.first;
            int steps=it.second.second;
            if(steps>k)continue;
            for(auto iterator:adj[node]){
              int adjnode=iterator.first;
int adjw=iterator.second;
if(wt+adjw<dist[adjnode] && steps<=k){
    dist[adjnode]=wt+adjw;
    q.push({adjnode,{dist[adjnode],steps+1}});
}
            }
        }
        if(dist[dst]==1e9)return -1;
        return dist[dst];
    }
};