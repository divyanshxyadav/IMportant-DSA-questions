class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int count=0;
        int ind=0;
        for(int i=0;i<mat.size();i++){
          int sum=0;
            for(int j=0;j<mat[0].size();j++){
if(mat[i][j]==1)
sum++;
            }
            if(sum>count){
                count=sum;
                ind=i;
            }
        }
        return {ind,count};
    }
};