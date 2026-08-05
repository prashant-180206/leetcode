/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */
#include <string>
using namespace std;

// @lc code=start
class WordDictionary
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
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        int idx = 0;
        TrieNode *node = root;

        while (idx < word.length())
        {
            int charIndex = word[idx] - 'a';

            if (node->children[charIndex] == nullptr)
                node->children[charIndex] = new TrieNode();

            node = node->children[charIndex];
            idx++;
        }
        node->isEndOfWord = true;
    }

    bool dfs(TrieNode *node, string &word, int idx)
    {
        if (node == nullptr)
            return false;

        if (idx == word.length())
            return node->isEndOfWord;

        if (word[idx] == '.')
        {
            for (int i = 0; i < 26; i++)
                if (dfs(node->children[i], word, idx + 1))
                    return true;

            return false;
        }

        return dfs(node->children[word[idx] - 'a'], word, idx + 1);
    }

    bool search(string word)
    {
        return dfs(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
