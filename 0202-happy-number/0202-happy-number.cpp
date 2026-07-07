class Solution {
public:
int square(int n){
    int ans=0;
    while(n>0){
        int rem=n%10;
        ans+=rem*rem;
        n/=10;
    }
    return ans;
}
    bool isHappy(int n) {
        int slow=n;
        int fast=n;
        do{
            slow=square(slow);
            fast=square(square(fast));
            if(slow==1 || fast==1)
            return true;
        }while(slow!=fast);
        return false;
    }
};