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

    node* findKthNode(int k) {
        node* fast = head;
        node* slow = head;

        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    linkedList l;
    for (;;) {
        int x;
        cin >> x;
        l.insertAtTail(x);
        if (x = -1) break;
    }
    int k;
    cin >> k;
    node* ans = l.findKthNode(k);
    cout << ans->val << " ";
    return 0;
}