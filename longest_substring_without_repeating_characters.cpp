#include <string>
using namespace std;

class Solution {
public:
    int check_repeating (string s)
    {
        if (s == "" || s.length() == 1)
            return (0);
        for (int i = 0; i < s.length() - 1; i++)
        {
            for (int j = i + 1; j <= s.length(); j++)
                if (s[j] == s[i])
                    return (1);
        }
        return (0);
    }
    
    int lengthOfLongestSubstring(string s) {
        int length = -999, temp_length;
        string temp = "";
        if (s == "")
            return (0);
        else if (s.length() == 1)
            return (1);
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j < s.length(); j++)
            {
                temp.push_back(s[j]);
                if (check_repeating(temp))
                {
                    temp_length = temp.length() - 1;
                    break;
                }
            }
            if (check_repeating(temp) != 1)
                temp_length = temp.length();
            if (temp_length > length)
                length = temp_length;
            if (length == 95)
                return (length);
            temp.clear();
        }
        return (length);
    }
};