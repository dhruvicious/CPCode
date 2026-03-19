#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Trie {
   private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;

        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;

    void dfs(TrieNode* node, string& path, vector<string>& result) {
        if (!node || result.size() == 3) return;

        if (node->isEndOfWord) result.push_back(path);

        for (int i = 0; i < 26 && result.size() < 3; i++) {
            if (node->children[i] != nullptr) {
                path.push_back(char(i + 'a'));
                dfs(node->children[i], path, result);
                path.pop_back();  // backtrack
            }
        }
    }

   public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEndOfWord = true;
    }

    bool search(string s) {
        TrieNode* curr = root;
        for (char ch : s) {
            int indx = ch - 'a';
            if (curr->children[indx] == nullptr) {
                return false;
            }
            curr = curr->children[indx];
        }
        return curr->isEndOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index];
        }
        return true;
    }

    vector<string> getSuggestions(string prefix) {
        TrieNode* curr = root;
        vector<string> result;

        // Traverse to prefix node
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr) return result;
            curr = curr->children[idx];
        }

        string path = prefix;
        dfs(curr, path, result);
        return result;
    }
};

class Solution {
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;

        sort(products.begin(), products.end());

        for (string& product : products) trie.insert(product);

        vector<vector<string>> answer;
        string prefix = "";

        for (char ch : searchWord) {
            prefix += ch;
            answer.push_back(trie.getSuggestions(prefix));
        }

        return answer;
    }
};
