class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int>st;
        for(auto s:candyType)
            st.insert(s);
if(st.size()>candyType.size()/2)
return candyType.size()/2;
else
return st.size();
    }
};