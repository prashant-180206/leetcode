/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */
#include <string>
using namespace std;

// @lc code=start
class Trie
{
    struct TrieNode
    {
        TrieNode *children[26];
        bool isEndOfWord;

        TrieNode()
        {
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
            isEndOfWord = false;
        }
    };

    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        int index = 0;
        TrieNode *node = root;
        while (index < word.length())
        {
            int charIndex = word[index] - 'a';

            if (node->children[charIndex] == nullptr)
                node->children[charIndex] = new TrieNode();

            node = node->children[charIndex];
            index++;
        }
        node->isEndOfWord = true;
    }

    bool search(string word)
    {
        int index = 0;
        TrieNode *node = root;
        while (index < word.length())
        {
            int charIndex = word[index] - 'a';

            if (node->children[charIndex] == nullptr)
                return false;

            node = node->children[charIndex];
            index++;
        }
        return node->isEndOfWord;
    }

    bool startsWith(string prefix)
    {
        int index = 0;
        TrieNode *node = root;
        while (index < prefix.length())
        {
            int charIndex = prefix[index] - 'a';

            if (node->children[charIndex] == nullptr)
                return false;

            node = node->children[charIndex];
            index++;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
