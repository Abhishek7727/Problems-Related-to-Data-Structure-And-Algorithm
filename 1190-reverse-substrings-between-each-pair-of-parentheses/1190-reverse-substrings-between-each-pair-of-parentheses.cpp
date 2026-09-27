class Solution {
public:
    string reverseParentheses(string s) {

        int totalParen = 0;

        // 1. Count parentheses
        for (char ch : s) {
            if (ch == '(' || ch == ')')
                totalParen++;
        }

        // 2. Final answer ka size
        int n = s.size() - totalParen;

        string ans(n, ' ');

        // 3. Matching parenthesis find karenge
        vector<int> match(s.size(), -1);

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {

                int balance = 1;

                for (int j = i + 1; j < s.size(); j++) {

                    if (s[j] == '(')
                        balance++;

                    else if (s[j] == ')') {
                        balance--;

                        if (balance == 0) {
                            match[i] = j;
                            match[j] = i;
                            break;
                        }
                    }
                }
            }
        }

        // 4. Traverse in the order in which characters
        // should appear in final answer
        int i = 0;
        int dir = 1;
        int currPos = 0;

        while (i >= 0 && i < s.size()) {

            if (s[i] == '(' || s[i] == ')') {

                // Matching bracket par jump
                i = match[i];

                // Direction reverse
                dir = -dir;
            }
            else {

                ans[currPos] = s[i];
                currPos++;
            }

            i += dir;
        }

        return ans;
    }
};