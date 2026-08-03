/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
            return "0";

        string result;

        if ((numerator < 0) ^ (denominator < 0))
            result += "-";

        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);

        result += to_string(num / den);
        num %= den;

        if (num == 0)
            return result;

        result += ".";

        unordered_map<long long, int> remainderIndex;
        while (num != 0)
        {
            if (remainderIndex.find(num) != remainderIndex.end())
            {
                result.insert(remainderIndex[num], "(");
                result += ")";
                break;
            }

            remainderIndex[num] = result.size();
            num *= 10;
            result += to_string(num / den);
            num %= den;
        }

        return result;
    }
};
// @lc code=end
