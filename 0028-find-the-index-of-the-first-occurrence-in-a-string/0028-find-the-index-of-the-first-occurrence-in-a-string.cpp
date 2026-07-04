class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0;
        int j=0;
        int n=haystack.size();
        int count=needle.size();
        while(i<n){
            if(haystack[i]==needle[j]){
                i++;
                j++;}
           
            else if(haystack[i]!=needle[j]){
                i-=j;
            i++;
            j=0; }
            if(j==count)
            return i-j;
           
            
        }
        return -1;
    }
};