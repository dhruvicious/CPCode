#include <iostream>

using namespace std;

class Node {
   public:
    int   val;
    Node *prev, *next, *child;
};

class LinkedList {
   private:
   public:
};

class Solution {
   private:
    Node* dfs(Node* head) {
        Node *curr = head, *last = head;
        while (curr) {
            Node* nextNode = curr->next;
            if (curr->child) {
                Node* childHead = curr->child;
                Node* childTail = dfs(childHead);

                curr->next      = childHead;
                childHead->prev = curr;

                curr->child = nullptr;

                if (nextNode) {
                    childTail->next = nextNode;
                    nextNode->prev  = childTail;
                }
                last = childTail;
            } else {
                last = curr;
            }
            curr = nextNode ? last->next : nullptr;
        }
        return last;
    }

   public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;

        dfs(head);
        return head;
    }
};

int main() {
}
