/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */
#include <queue>
using namespace std;
// @lc code=start
class MyStack
{
    queue<int> primary;
    queue<int> helper;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        while (!primary.empty())
        {
            helper.push(primary.front());
            primary.pop();
        }
        primary.push(x);
        while (!helper.empty())
        {
            primary.push(helper.front());
            helper.pop();
        }
    }

    int pop()
    {
        int val = primary.front();
        primary.pop();
        return val;
    }

    int top()
    {
        return primary.front();
    }

    bool empty()
    {
        return primary.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
