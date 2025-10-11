#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    int val;
    node* next;
    node() { next = nullptr; }
    node(int data = 0) {
        val = data;
        next = nullptr;
    }
};
void insertAtTail(node*& head, node*& tail, int data);
void insertAtHead(node*& head, node*& tail, int data);
void printList(node* head);

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

node* sumList(node* head1, node* head2) {
    node* answerNode = new node(0);
    node* curr = answerNode;
    int carry = 0;
    while (head1 != nullptr || head2 != nullptr || carry != 0) {
        int val1 = (head1 != nullptr) ? head1->val : 0;
        int val2 = (head2 != nullptr) ? head2->val : 0;

        int total = val1 + val2 + carry;
        carry = total / 10;
        int remainder = total % 10;

        curr->next = new node(remainder);
        curr = curr->next;

        if (head1 != nullptr) {
            head1 = head1->next;
        }
        if (head2 != nullptr) {
            head2 = head2->next;
        }
    }
    return answerNode->next;
}

node* reverseLinkedList(node* head) {
    node* prev = nullptr;
    node* curr = head;
    node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;  // Store next node
        curr->next = prev;  // Reverse current node's pointer
        prev = curr;        // Move prev to current
        curr = next;        // Move to next node
    }
    return prev;  // New head
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;

    node *head1 = nullptr, *tail1 = nullptr;
    node *head2 = nullptr, *tail2 = nullptr;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        insertAtHead(head1, tail1, data);
    }
    for (int i = 0; i < m; i++) {
        int data;
        cin >> data;
        insertAtHead(head2, tail2, data);
    }
    node* ans = sumList(head1, head2);
    ans = reverseLinkedList(ans);

    printList(ans);
    return 0;
}