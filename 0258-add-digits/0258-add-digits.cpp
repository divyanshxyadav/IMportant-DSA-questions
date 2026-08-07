class Solution {
public:
    int addDigits(int num) {
      int temp=num;  int ans=0;
        while(true){
         
         ans=0;
while(temp>0){
   ans+= temp%10;
   temp/=10;
}
if(ans<10){
    return ans;
}
else
temp=ans;
        }
        return 0;
    }
};