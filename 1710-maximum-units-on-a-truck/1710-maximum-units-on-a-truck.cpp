class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        for(auto &it: boxTypes){
            reverse(it.begin(),it.end());}
            sort(boxTypes.rbegin(),boxTypes.rend());
            int i=0;
            int ans=0;
            while(truckSize>0 && i<boxTypes.size()){
                if(boxTypes[i][1]<=truckSize){
                ans+=boxTypes[i][1]*boxTypes[i][0];
                truckSize-=boxTypes[i][1];
                }
                else{
                     ans+=truckSize*boxTypes[i][0];
                     truckSize=0;
                }
                i++;
            }
            return ans;
    }
};