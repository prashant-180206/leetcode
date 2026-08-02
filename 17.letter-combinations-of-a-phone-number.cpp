/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution
{
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        if (digits.empty())
            return result;
        string combination = "";
        backtrack(digits, 0, combination, result);
        return result;
    }

private:
    void backtrack(const string &digits, int index, string &combination, vector<string> &result)
    {
        if (index == digits.length())
        {
            result.push_back(combination);
            return;
        }
        char digit = digits[index];
        const string &letters = mp[digit];
        for (char letter : letters)
        {
            combination.push_back(letter);
            backtrack(digits, index + 1, combination, result);
            combination.pop_back();
        }
    }
};
// @lc code=end
