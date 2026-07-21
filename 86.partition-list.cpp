/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode lessdummy(0);
        ListNode moredummy(0);

        ListNode *curr = head;
        ListNode *lesscurr = &lessdummy;
        ListNode *morecurr = &moredummy;
        while (curr)
        {
            if (curr->val < x)
            {
                lesscurr->next = curr;
                lesscurr = lesscurr->next;
            }
            else
            {
                morecurr->next = curr;
                morecurr = morecurr->next;
            }
            curr = curr->next;
        }

        morecurr->next = nullptr;

        lesscurr->next = moredummy.next;

        return lessdummy.next;
    }
};
// @lc code=end
