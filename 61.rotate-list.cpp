/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        int size = 1;
        ListNode *curr = head;

        while (curr->next)
        {
            curr = curr->next;
            size++;
        }
        k = k % size;

        if (k == 0)
            return head;

        curr->next = head;

        ListNode *lastnode = head;

        for (int i = 0; i < size - k - 1; i++)
            lastnode = lastnode->next;

        ListNode *newhead = lastnode->next;
        lastnode->next = nullptr;

        return newhead;
    }
};
// @lc code=end
