#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    int val;
    node* next;

    node(int data = 0) {
        this->next = nullptr;
        this->val = data;
    }
};
void insertAtTail(node*& head, node*& tail, int val);
void insertAtHead(node*& head, node*& tail, int val);
void printList(node* head);
int lenOfList(node* head);

void insertAtTail(node*& head, node*& tail, int val) {
    node* newNode = new node(val);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtHead(node*& head, node*& tail, int val) {
    node* newNode = new node(val);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void printList(node* head) {
    while (head) {
        cout << head->val << "-->";
        head = head->next;
    }
    cout << endl;
}

int lenOfList(node* head) {
    if (!head) return 0;
    int len = 1;
    while (head) {
        head = head->next;
        len += 1;
    }
    return len;
}

node* reverseList(node* head) {
    node* prev = nullptr;
    node* curr = head;
    node* next = nullptr;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, x;
    cin >> n >> x;

    node *head = nullptr, *tail = nullptr;

    while (n--) {
        int val = NULL;
        cin >> val;
        insertAtTail(head, tail, val);
    }
    return 0;
}