/*
 * @lc app=leetcode id=648 lang=cpp
 *
 * [648] Replace Words
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution
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

        void insert(string &word)
        {
            TrieNode *node = this;
            for (char c : word)
            {
                int index = c - 'a';
                if (node->children[index] == nullptr)
                    node->children[index] = new TrieNode();
                node = node->children[index];
            }
            node->isEndOfWord = true;
        }

        string prefix(string &word)
        {
            TrieNode *node = this;
            string result;
            for (char c : word)
            {
                int index = c - 'a';
                if (node->children[index] == nullptr)
                    return "";
                result += c;
                node = node->children[index];
                if (node->isEndOfWord)
                    return result;
            }
            return "";
        }
    };

    TrieNode *root;

public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        root = new TrieNode();
        for (string &word : dictionary)
            root->insert(word);

        string result;
        string currentWord;

        for (int i = 0; i <= sentence.length(); i++)
        {
            char c = (i < sentence.length()) ? sentence[i] : ' ';

            if (c == ' ' || i == sentence.length())
            {
                if (!currentWord.empty())
                {
                    string prefix = root->prefix(currentWord);
                    if (!prefix.empty())
                        result += prefix + ' ';
                    else
                        result += currentWord + ' ';
                    currentWord.clear();
                }
            }
            else
            {
                currentWord += c;
            }
        }
        result.pop_back();
        return result;
    }
};
// @lc code=end
