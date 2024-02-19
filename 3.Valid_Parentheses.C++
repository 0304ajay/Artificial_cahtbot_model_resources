//link -https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        // Declaration
        stack<char> stk;

        // LOGIC
        for (int itr = 0; itr < s.size(); itr++) {
            if (s[itr] == '(' || s[itr] == '[' || s[itr] == '{') {
                stk.push(s[itr]);
            } else if (stk.size() >= 1) // if stack is empty edge case "]"
            {
                if (s[itr] == ')' && stk.top() == '(') {
                    stk.pop();
                } else if (s[itr] == '}' && stk.top() == '{') {
                    stk.pop();
                } else if (s[itr] == ']' && stk.top() == '[') {
                    stk.pop();
                } else // if the bracket does not match
                {
                    return false;
                }
            } else // if the stack is empty
            {
                return false;
            }
        }
        return stk.empty();
    }
};
