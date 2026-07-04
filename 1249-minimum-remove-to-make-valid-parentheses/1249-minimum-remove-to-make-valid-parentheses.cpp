class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        stack<char> sta;

        for (char ch : s) {
            if (isalpha(ch))
                ans += ch;
            else if (ch == '(') {
                sta.push(ch);
                ans += ch;
            } else { 
                if (sta.empty())
                    continue;
                ans += ch;
                sta.pop();
            }
        }

        stack<int> stam;

        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == '(')
                stam.push(i);
            else if (ans[i] == ')') {
                if (stam.empty())
                    ans[i] = '*';
                else
                    stam.pop();
            }
        }

        while (!stam.empty()) {
            ans[stam.top()] = '*';
            stam.pop();
        }

        string finalans;
        for (char c : ans) {
            if (c != '*')
                finalans += c;
        }

        return finalans;
    }
};