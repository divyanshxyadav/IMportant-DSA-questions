class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cntneg=0;
        for(auto t:nums){
            if(t<0)
            cntneg++;
            else if(t==0)
            return 0;
        }
if(cntneg%2==0)
return 1;
return -1;
    }
};