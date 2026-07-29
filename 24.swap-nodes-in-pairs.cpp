/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode dummy = ListNode(0);
        dummy.next = head;

        auto prev = &dummy;

        while (prev->next && prev->next->next)
        {
            auto a = prev->next;
            auto b = prev->next->next;

            auto next1 = prev->next->next->next;

            a->next = next1;
            b->next = a;
            prev->next = b;
            prev = a;
        }

        return dummy.next;
    }
};
// @lc code=end
