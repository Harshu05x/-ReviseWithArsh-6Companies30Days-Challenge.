# Design Add and Search Words Data Structure

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/design-add-and-search-words-data-structure/description/)

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:
- WordDictionary() Initializes the object.
- void addWord(word) Adds word to the data structure, it can be matched later.
- bool search(word) Returns true if there is any string in the data structure that matches word or false 
otherwise. word may contain dots '.' where dots can be matched with any letter.

### Sample Input
```
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
```

### Sample Output
```
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
```

### Solution
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class WordDictionary {
public:

    struct TrieNode {
        bool isEnd;
        TrieNode *child[26];

        TrieNode() {
            isEnd = false;
            for(int i = 0; i < 26; i++) child[i] = NULL;
        }

    };

    TrieNode *root;

    WordDictionary() {
        root = new TrieNode();      
    }
    
    void addWord(string word) {
        TrieNode *cur = root;
        for(auto &c : word) {
            int idx = c - 'a';
            if(!cur->child[idx]) {
                cur->child[idx] = new TrieNode();
            }
            cur = cur->child[idx];
        }
        cur->isEnd = true;
    }
    
    bool search(string word, TrieNode *head = nullptr) {
        TrieNode *cur = head ? head : root;
        for(int j = 0; j < word.size(); j++) {
            char c = word[j];
            if(c == '.') {
                for(int i = 0; i < 26; i++) {
                    if(cur->child[i] && search(word.substr(j + 1), cur->child[i])) {
                        return true;
                    }
                }
                return false;
            }
            else {
                int idx = c - 'a';
                if(!cur->child[idx]) return false;
                cur = cur->child[idx];
            }
        }
        return cur->isEnd;
    }
};
```
