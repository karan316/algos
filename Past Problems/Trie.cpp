#include <bits/stdc++.h>

using namespace std;

struct TrieNode
{
    bool is_word;
    TrieNode *child[26];
    TrieNode()
    {
        is_word = false;
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};
class Trie
{
private:
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        int n = word.size();
        int pos = 0;
        TrieNode *curr = root;
        for (int i = 0; i < n; i++)
        {
            pos = word[i] - 'a';
            if (curr->child[pos] == NULL)
                curr->child[pos] = new TrieNode();
            curr = curr->child[pos];
        }
        curr->is_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        int n = word.size();
        int pos = 0;
        TrieNode *curr = root;
        for (int i = 0; i < n; i++)
        {
            pos = word[i] - 'a';
            if (curr->child[pos] == NULL)
                return false;
            curr = curr->child[pos];
        }
        return curr->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        int n = prefix.size();
        int pos = 0;
        TrieNode *curr = root;
        for (int i = 0; i < n; i++)
        {
            pos = prefix[i] - 'a';
            if (curr->child[pos] == NULL)
                return false;
            curr = curr->child[pos];
        }
        return true;
    }
};

int main()
{
}