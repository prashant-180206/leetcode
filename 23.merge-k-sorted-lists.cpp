#include <vector>
#include <algorithm>
#include <iostream>
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
public:
    bool areListsEmpty(vector<ListNode *> &lists)
    {
        // cout<<"areListsEmpty called"<<endl;
        bool ans = true;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != nullptr)
            {
                ans = false;
                break;
            }
        }
        return ans;
    }

    ListNode *getNextNode(vector<ListNode *> &lists)
    {
        // cout<<"getNextNode called"<<endl;
        ListNode *ans = nullptr;
        int pos = -1;
        int minnum = INT_MAX;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] == nullptr)
                continue;
            if (minnum > lists[i]->val)
            {
                pos = i;
                minnum = lists[i]->val;
            }
        }
        ans = lists[pos];

        lists[pos] = lists[pos]->next;

        return ans;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<ListNode *> listCopy = lists;
        ListNode dummyhead(0);
        ListNode *tail = &dummyhead;

        while (!areListsEmpty(listCopy))
        {
            // ListNode * current = ans;
            ListNode *nextNode = getNextNode(listCopy);
           
            tail->next = nextNode;
            tail = tail->next;
        }

        return dummyhead.next;
    }
};
// @lc code=end
