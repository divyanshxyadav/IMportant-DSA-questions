class Solution {
public:
    int smallestNumber(int n, int t) { 
   
        while(true){
        int temp=n;
        int val=1;
while(temp>0){
val*=temp%10;
temp/=10;
}
if(val%t==0)
return n;
n++;
        }
        return -1;
    }
};