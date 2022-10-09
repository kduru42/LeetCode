#include <string>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        int valid_count = 0;
        check.push('x');
        if (s.length() == 0)
            return (false);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                check.push(s[i]);
                valid_count++;
            }
            else if (s[i] == ')')
                if (check.top() != '(')
                    return (false);
                else
                {
                    check.pop();
                    valid_count--;
                }
            else if (s[i] == ']')
                if (check.top() != '[')
                    return (false);
                else
                {
                    check.pop();
                    valid_count--;
                }
            else if (s[i] == '}')
                if (check.top() != '{')
                    return (false);
                else
                {
                    check.pop();
                    valid_count--;
                }
        }
        if (!valid_count)
            return (true);
        else
            return (false);
    }
};
