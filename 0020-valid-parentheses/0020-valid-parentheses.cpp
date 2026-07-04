class Solution {
public:
    bool isValid(string s) {
stack<char>st;
for(auto a:s){
if(a=='(' ||a=='{' ||a=='['){
st.push(a);
}
else{
    if(st.empty())
    return false;
if(a==')' && st.top()!='(')
return false;
else if(a=='}' && st.top()!='{')
return false;
else if(a==']' && st.top()!='[')
return false;
else
st.pop();
}
}return st.empty();}
};