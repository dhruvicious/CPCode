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
node* appendKNodesToLast(node* head, int k);
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

int lenOfList(node* head){
    if(!head) return 0;
    int len = 1;
    while(head){
        head = head->next;
        len++;
    }
    return len;
}

node* appendKNodesToLast(node* head, int k) {
    if (!head || k == 0) return head;

    node* temp = head;
    int len = lenOfList(head);
    k = k % len;
    if (k == 0) {
        return head;
    }
    temp->next = head;
    int stepsToNewHead = len - k;

    node* newTail = head;
    while (stepsToNewHead--) {
        newTail = newTail->next;
    }
    node* newHead = newTail->next;
    newTail->next= nullptr;

    return newHead;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    node* head = nullptr;
    node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertAtTail(head, tail, val);
    }

    int k;
    cin >> k;
    return 0;
}