#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    int val;
    node* next;
    node(int data = 0) {
        val = data;
        next = nullptr;
    }
};

class linkedList {
    node *head, *tail;

   public:
    linkedList() { head = tail = nullptr; }

    void insertAtTail(int data) {
        node* newNode = new node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList() {
        node* temp = head;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}