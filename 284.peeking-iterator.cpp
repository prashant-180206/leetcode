/*
 * @lc app=leetcode id=284 lang=cpp
 *
 * [284] Peeking Iterator
 */
#include <vector>
using namespace std;

class Iterator
{
	struct Data;
	Data *data;

public:
	Iterator(const vector<int> &nums);
	Iterator(const Iterator &iter);

	// Returns the next element in the iteration.
	int next();

	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

// @lc code=start
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator
{
	int nextElement;
	bool hasNextElement;

public:
	PeekingIterator(const vector<int> &nums) : Iterator(nums)
	{
		if (Iterator::hasNext())
		{
			nextElement = Iterator::next();
			hasNextElement = true;
		}
		else
		{
			hasNextElement = false;
		}
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek()
	{
		return nextElement;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next()
	{
		int currentElement = nextElement;
		if (Iterator::hasNext())
		{
			nextElement = Iterator::next();
			hasNextElement = true;
		}
		else
		{
			hasNextElement = false;
		}
		return currentElement;
	}

	bool hasNext() const
	{
		return hasNextElement;
	}
};
// @lc code=end
