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
void insertAtTail(node*& head, node*& tail, int data);
void printList(node* head);
node* reverseList(node* head);
node* mergeLists(node* head1, node* head2);

void insertAtTail(node*& head, node*& tail, int data) {
    node* newNode = new node(data);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtHead(node*& head, node*& tail, int data) {
    node* newNode = new node(data);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
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
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

node* mergeLists(node* head1, node* head2) {
    node* dummy = new node(0);
    node* tail = dummy;
    while (head1 && head2) {
        if (head1->val < head2->val) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    tail->next = head1 ? head1 : head2;
    return dummy->next;
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
    node* h2 = nullptr;
    node* t2 = nullptr;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertAtTail(h1, t1, val);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        insertAtTail(h2, t2, val);
    }
    node* ans = mergeLists(h1, h2);
    printList(ans);
    return 0;
}