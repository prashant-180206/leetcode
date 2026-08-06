/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 */
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution
{

    unordered_map<int, string> bignum{
        {1, "Thousand"},
        {2, "Million"},
        {3, "Billion"}};

    unordered_map<int, string> numToWords = {
        {0, "Zero"},
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"}};

    string digit3towords(int num)
    {
        if (num == 0)
            return "";

        if (num < 20)
            return numToWords[num];

        if (num < 100)
            return numToWords[num / 10 * 10] + (num % 10 ? " " + digit3towords(num % 10) : "");

        return numToWords[num / 100] + " Hundred" + (num % 100 ? " " + digit3towords(num % 100) : "");
    }

public:
    string numberToWords(int num)
    {
        if (num == 0)
            return numToWords[0];

        string result;
        int i = 0;

        while (num > 0)
        {
            int curr = num % 1000;
            if (curr != 0)
            {
                string currWords = digit3towords(curr);
                if (!result.empty())
                    result = currWords + " " + bignum[i] + " " + result;
                else
                    result = currWords + " " + bignum[i];
            }
            num /= 1000;
            i++;
        }

        while (!result.empty() && result.back() == ' ')
            result.pop_back();

        return result;
    }
};
// @lc code=end
