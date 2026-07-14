/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        ListNode *current = head;
        ListNode *forwardptr = head;
        int currentpos = 0;

        while (currentpos < n && forwardptr != nullptr)
        {
            forwardptr = forwardptr->next;
            currentpos++;
        }

        if (forwardptr == nullptr)
        {
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }

        while (forwardptr->next != nullptr)
        {
            current = current->next;
            forwardptr = forwardptr->next;
        }
        ListNode *dummy = current->next;
        current->next = current->next->next;
        delete dummy;

        return head;
    }
};
// @lc code=end
