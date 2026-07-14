/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *curr = head;
        ListNode *prev = &dummy;

        while (curr)
        {
            if (curr->next && curr->val == curr->next->val)
            {
                int dupval = curr->val;

                while (curr && curr->val == dupval)
                {
                    ListNode *todel = curr;
                    curr = curr->next;
                    delete todel;
                }
                prev->next = curr;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};
// @lc code=end
