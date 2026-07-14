/*
 * @lc app=leetcode id=407 lang=cpp
 *
 * [407] Trapping Rain Water II
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    int trapRainWater(vector<vector<int>> &arr)
    {
        if (arr.size() == 0)
            return 0;

        int ans = 0;
        int rows = arr.size();
        int cols = arr[0].size();
        int lmax = 0, rmax = 0, fmax = 0, bmax = 0;

        int hposr = cols - 1;
        int lposr = 0;
        int hposc = rows - 1;
        int lposc = 0;

        while (lposr < hposr)
        {
            lmax = max(lmax, lposr);
            rmax = max(rmax, hposr);

            int minrow;
            int rpos;
            if (lposr < hposr)
            {
                rpos = lposr;
                minrow = lposr;
                lposr++;
            }
            else
            {
                rpos = hposr;
                minrow = hposr;
                hposr--;
            }
            while (lposr < hposr)
            {
                fmax = max(fmax, lposc);
                bmax = max(fmax, lposc);

                int minval = minrow;
                if (lposc < hposc)
                {
                    minval = min(minval, lposc);
                    ans += minval - (arr[rpos][lposc]);
                    lposc++;
                }
                else
                {
                    minval = min(minval, hposc);
                    ans += minval - (arr[rpos][hposc]);
                    hposc--;
                }
            }
        }
    }
};
// @lc code=end
