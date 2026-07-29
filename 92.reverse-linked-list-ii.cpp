/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode dummy(0);
        dummy.next = head;
        int count = 1;

        auto prev = &dummy;
        while (count < left)
        {
            prev = prev->next;
            count++;
        }

        auto curr = prev->next;

        while (count < right)
        {
            auto next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            count++;
        }

        return dummy.next;
    }
};
// @lc code=end
