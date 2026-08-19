class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<array<int,3>>sortedTasks;
        for(int i=0;i<n;i++){
            int st=tasks[i][0];
            int pr=tasks[i][1];
            sortedTasks.push_back({st,pr,i});
        }
        sort(sortedTasks.begin(),sortedTasks.end());
        vector<int>result;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        long long curr=0;
        int idx=0;
        while(idx<n || !pq.empty()){
            if(pq.empty()&& curr<sortedTasks[idx][0])
            curr=sortedTasks[idx][0];
            while(idx<n && sortedTasks[idx][0]<=curr){
                pq.push({sortedTasks[idx][1],sortedTasks[idx][2]});
                idx++;
            }
            pair<int,int>curr_task=pq.top();
            pq.pop();
            curr+=curr_task.first;
            result.push_back(curr_task.second);
        }
        return result;
    }
};