/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k == 1)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        int len = 0;
        ListNode *curr = head;
        while (curr)
        {
            len++;
            curr = curr->next;
        }

        ListNode *prevGroup = &dummy;

        while (len >= k)
        {
            ListNode *curr = prevGroup->next;

            for (int i = 0; i < k - 1; i++)
            {
                ListNode *move = curr->next;

                curr->next = move->next;
                move->next = prevGroup->next;
                prevGroup->next = move;
            }

            prevGroup = curr;
            len -= k;
        }

        return dummy.next;
    }
};
// @lc code=end
