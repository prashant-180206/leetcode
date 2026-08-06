/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution
{

public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> charToWord;
        int i = 0;

        string currentWord;
        int wordIndex = 0;

        while (i <= s.length())
        {
            if (i == s.length() || s[i] == ' ')
            {
                char currentChar = pattern[wordIndex];

                if (charToWord.find(currentChar) != charToWord.end())
                {
                    if (charToWord[currentChar] != currentWord)
                        return false;
                }
                else
                {
                    for (const auto &pair : charToWord)
                    {
                        if (pair.second == currentWord)
                            return false;
                    }
                    charToWord[currentChar] = currentWord;
                }

                currentWord.clear();
                wordIndex++;
            }
            else
            {
                currentWord += s[i];
            }
            i++;
        }

        return wordIndex == pattern.size();
    }
};
// @lc code=end
