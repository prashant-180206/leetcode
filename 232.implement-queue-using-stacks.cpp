/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */
#include <stack>
using namespace std;

// @lc code=start
class MyQueue
{
    stack<int> primary;
    stack<int> helper;

public:
    MyQueue() {}

    void push(int x)
    {
        while(!primary.empty()){
            helper.push(primary.top());
            primary.pop();
        }
        primary.push(x);
        while (!helper.empty())
        {
            primary.push(helper.top());
            helper.pop();
        }
        
    }

    int pop()
    {
        int val = primary.top();
        primary.pop();
        return val;
    }

    int peek()
    {
        return primary.top();
    }

    bool empty()
    {
        return primary.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
