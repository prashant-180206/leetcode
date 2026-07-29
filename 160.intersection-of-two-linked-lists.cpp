/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        int len1 = 0;
        auto curr = headA;
        while (curr)
        {
            curr = curr->next;
            len1++;
        }

        int len2 = 0;
        curr = headB;
        while (curr)
        {
            curr = curr->next;
            len2++;
        }

        int diff = len1 - len2;
        ListNode *h1 = headA;
        ListNode *h2 = headB;

        if (diff < 0)
            for (int i = 0; i < diff * -1; i++)
                h2 = h2->next;
        else
            for (int i = 0; i < diff; i++)
                h1 = h1->next;

        while (h1 && h2 && h1 != h2)
        {
            h1 = h1->next;
            h2 = h2->next;
        }
        return h1;
    }
};
// @lc code=end
