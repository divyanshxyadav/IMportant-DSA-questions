class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
      int ans=0;
      for(auto s:sentences){
        int cnt=1;
        for(auto c:s){
            if(c==' ')
            cnt++;
        }
        ans=max(ans,cnt);
      }
      return ans;
    }
};