// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
int first(int m){
    while(m>0 && isBadVersion(m)){
        m--;
    }
    return m+1;
}
    int firstBadVersion(int n) {
        int l=1,h=n;
        while(l<=h){
            int m=l+(h-l)/2;
            if(isBadVersion(l))
            return l;
            else if(isBadVersion(m))
           return first(m);
else
    l=m+1;

        }
        return 0;
    }
};