#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    int   val;
    node* next;
    node(int data = 0) {
        val  = data;
        next = nullptr;
    }
};
void insertAtTail(node*& head, node*& tail, int data) {
    node* newNode = new node(data);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail       = newNode;
    }
}

void printList(node* head) {
    node* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

node* reverseList(node* head) {
    node* prev = nullptr;
    node* curr = head;
    node* next = nullptr;

    while (curr != nullptr) {
        next       = curr->next;
        curr->next = prev;
        prev       = curr;
        curr       = next;
    }
    return prev;
}

node* deleteNodes(node* head) {
    head = reverseList(head);

    node* curr     = head;
    node* prev     = nullptr;
    int   maxSoFar = INT_MIN;

    while (curr != nullptr) {
        if (curr->val >= maxSoFar) {
            maxSoFar = curr->val;
            prev     = curr;
            curr     = curr->next;
        } else {
            node* temp = curr;
            curr       = curr->next;
            if (prev) {
                prev->next = curr;
            } else {
                head = curr;
            }
            delete temp;
        }
    }
    head = reverseList(head);
    return head;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    node* h1 = nullptr;
    node* t1 = nullptr;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertAtTail(h1, t1, val);
    }

    node* ans = deleteNodes(h1);
    printList(ans);
    return 0;
}