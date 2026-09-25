#include <string>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
    // Helper function to combine two sets of strings via concatenation (Cartesian product)
    set<string> combineProduct(const set<string>& set1, const set<string>& set2) {
        set<string> result;
        for (const string& s1 : set1) {
            for (const string& s2 : set2) {
                result.insert(s1 + s2);
            }
        }
        return result;
    }

    // Helper function to combine two sets via union
    set<string> combineUnion(const set<string>& set1, const set<string>& set2) {
        set<string> result = set1;
        result.insert(set2.begin(), set2.end());
        return result;
    }

public:
    vector<string> braceExpansionII(string expression) {
        stack<char> ops;
        stack<set<string>> operandStack;

        // Process operators based on priority
        // Concatenation (*) has higher precedence than Union (+)
        auto evaluateTop = [&](char op) {
            set<string> right = operandStack.top(); operandStack.pop();
            set<string> left = operandStack.top(); operandStack.pop();
            
            if (op == '*') {
                operandStack.push(combineProduct(left, right));
            } else if (op == '+') {
                operandStack.push(combineUnion(left, right));
            }
        };

        for (int i = 0; i < expression.length(); ++i) {
            char c = expression[i];

            // If implicit multiplication occurs (e.g., 'a{' or '}a' or '}{' or 'ab')
            if (i > 0) {
                char prev = expression[i - 1];
                if ((isalpha(prev) || prev == '}') && (isalpha(c) || c == '{')) {
                    while (!ops.empty() && ops.top() == '*') {
                        evaluateTop(ops.top());
                        ops.pop();
                    }
                    ops.push('*'); // Insert implicit concatenation operator
                }
            }

            if (isalpha(c)) {
                string str = "";
                while (i < expression.length() && isalpha(expression[i])) {
                    str += expression[i];
                    i++;
                }
                i--; // Step back after matching word
                operandStack.push({str});
            } else if (c == '{') {
                ops.push(c);
            } else if (c == ',') {
                while (!ops.empty() && ops.top() != '{') {
                    evaluateTop(ops.top());
                    ops.pop();
                }
                ops.push('+'); // Treat comma as union operator
            } else if (c == '}') {
                while (!ops.empty() && ops.top() != '{') {
                    evaluateTop(ops.top());
                    ops.pop();
                }
                ops.pop(); // Remove matching '{'
            }
        }

        // Evaluate remaining operations
        while (!ops.empty()) {
            evaluateTop(ops.top());
            ops.pop();
        }

        // Extract result sorted automatically by std::set
        set<string> resultSet = operandStack.top();
        return vector<string>(resultSet.begin(), resultSet.end());
    }
};