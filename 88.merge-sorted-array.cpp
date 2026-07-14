/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &arr1, int m, vector<int> &arr2, int n)
    {
        int ptr1 = m - 1;
        int ptr2 = n - 1;
        int insert = m + n - 1;

        while (ptr1 >= 0 && ptr2 >= 0)
        {
            if (arr1[ptr1] > arr2[ptr2])
                arr1[insert--] = arr1[ptr1--];
            else
                arr1[insert--] = arr2[ptr2--];
        }
        if (ptr1 < 0 && !(ptr2 < 0))
            while (ptr2 >= 0)
                arr1[insert--] = arr2[ptr2--];

        if (ptr2 < 0 && !(ptr1 < 0))
            while (ptr1 >= 0)
                arr1[insert--] = arr1[ptr1--];
    }
};
// @lc code=end
