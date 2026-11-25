#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Valid Parentheses.
// https://leetcode.com/problems/valid-parentheses/description/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st = {};
        for (char c : s) {
            switch (c) {
            case '(': st.push(')'); break;
            case '{': st.push('}'); break;
            case '[': st.push(']'); break;
            default: if (st.empty() || st.top() != c) return false;
            st.pop();
            }
        }
        return st.empty();
    }
};

int main(void) {
    Solution s{};
    string expr = "[]({}()(()(())){})[]";
    cout << s.isValid(expr) << endl;

    return 0;
}
