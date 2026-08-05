#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    struct Compare
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val; // Min heap
        }
    };

    priority_queue<ListNode *, vector<ListNode *>, Compare> pq;

    bool initialized = false;

public:
    ListNode *getNextNode(vector<ListNode *> &lists)
    {
        if (!initialized)
        {
            for (ListNode *head : lists)
                if (head)
                    pq.push(head);

            initialized = true;
        }

        if (pq.empty())
            return nullptr;

        ListNode *node = pq.top();
        pq.pop();

        if (node->next)
            pq.push(node->next);

        return node;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode dummyhead(0);
        ListNode *tail = &dummyhead;

        while (true)
        {
            ListNode *nextNode = getNextNode(lists);

            if (nextNode == nullptr)
                break;

            tail->next = nextNode;
            tail = tail->next;
        }

        return dummyhead.next;
    }
};

// @lc code=end
