#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    int data;
    node *next;
    node(int data = 0) {
        this->data = data;
        this->next = nullptr;
    }
};

void insertAtTail(node *&head, node *&tail, int data) {
    node *newNode = new node(data);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtHead(node *&head, node *&tail, int data) {
    node *newNode = new node(data);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

int lenOfList(node *head) {
    if (!head) return 0;
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

void printList(node *head) {
    if (!head) return;
    cout << head->data << " ";
    printList(head->next);
}

node *reverseList(node *head) {
    node *prev = nullptr, *curr = head, *next = nullptr;
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
    node *head = nullptr, *tail = nullptr;
    int n;
    cin >> n;

    node *ansHead = nullptr;
    node *ansTail = nullptr;

    while (n--) {
        int val;
        cin >> val;
        insertAtHead(head, tail, val);
    }
    int i = 0;
    int ans = 0;
    while (head) {
        ans += (head->data) * (1 << i++);
        head = head->next;
    }
    cout<<ans;
    return 0;
}
