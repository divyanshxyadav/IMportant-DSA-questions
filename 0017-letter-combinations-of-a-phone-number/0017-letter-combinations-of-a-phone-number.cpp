class Solution {
public:
 vector<string>results;
void solve(int idx,string &digits,string &temp,unordered_map<char,string>&mpp){
    if(idx>=digits.size()){
        results.push_back(temp);
        return;
    }
    char ch=digits[idx];
    string str=mpp[ch];
    for(int i=0;i<str.length();i++){
        temp.push_back(str[i]);
        solve(idx+1,digits,temp,mpp);
        temp.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
        return {};
       string temp="";
       unordered_map<char,string>mpp;
mpp['3'] = "def";
mpp['2'] = "abc";
mpp['4'] = "ghi";
mpp['5'] = "jkl";
mpp['6'] = "mno";
mpp['7'] = "pqrs";
mpp['8'] = "tuv";
mpp['9'] = "wxyz";
solve(0,digits,temp,mpp);
return results;
    }
};