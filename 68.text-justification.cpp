/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ans;

        int i = 0;
        while (i < words.size())
        {
            int charcount = 0;
            int j = i;
            while (j < words.size() && charcount + words[j].length() + (j - i) <= maxWidth)
            {
                charcount += words[j].length();
                j++;
            }

            int spacecount = maxWidth - charcount;
            int gaps = j - i - 1;

            string line;
            if (j == words.size() || gaps == 0)
            {
                for (int k = i; k < j; k++)
                {
                    line += words[k];
                    if (k < j - 1)
                        line += " ";
                }
                line += string(maxWidth - line.length(), ' ');
            }
            else
            {
                int spacesPerGap = spacecount / gaps;
                int extraSpaces = spacecount % gaps;

                for (int k = i; k < j; k++)
                {
                    line += words[k];
                    if (k < j - 1)
                    {
                        line += string(spacesPerGap + (k - i < extraSpaces ? 1 : 0), ' ');
                    }
                }
            }
            ans.push_back(line);
            i = j;
        }
        return ans;
    }
};
// @lc code=end
