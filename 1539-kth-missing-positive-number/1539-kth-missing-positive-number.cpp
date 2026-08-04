class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
      for(auto p:arr){
        if(p<=k)k++;
        else
        break;
      }
      return k;
    }
};