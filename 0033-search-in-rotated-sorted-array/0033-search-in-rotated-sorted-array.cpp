class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0;
        for(auto n:nums){
++i;
            if(n==target)
            return i-1;
        }
        return -1;
    }
};