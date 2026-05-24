#include <unordered_map>

using namespace std;

class LRUCache {
   private:
    struct Node {
        int   key, val;
        Node *prev, *next;

        Node(int k, int v) {
            key  = k;
            val  = v;
            prev = next = nullptr;
        }
    };

    int                                               cap;
    unordered_map<int /*Key */, Node* /*CacheList */> mp;
    Node *                                            head, *tail;

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertFront(Node* node) {
        node->next       = head->next;
        node->prev       = head;
        head->next->prev = node;
        head->next       = node;
    }

   public:
    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];
        removeNode(node);
        insertFront(node);
        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val  = value;

            removeNode(node);
            insertFront(node);

            return;
        }

        if (mp.size() == cap) {
            Node* LRU = tail->prev;
            removeNode(LRU);
            mp.erase(LRU->key);

            delete LRU;
        }

        Node* newNode = new Node(key, value);
        insertFront(newNode);
        mp[key] = newNode;
    }
};
