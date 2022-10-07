#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = "";
        int flag = 0;
        char c;
        for (int i = 0; i < strs[0].length(); i++)
        {
            c = strs[0][i];
            for (int j = 0; j < strs.size(); j++)
            {
                if (strs[j][i] != c)
                    flag = 1;
            }
            if (flag == 0)
                common.push_back(c);
            else
                break;
        }
        return (common);
    }
};