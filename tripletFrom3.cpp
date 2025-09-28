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
void insertAtTail(node*& head, node*& tail, int data) {
    node* newNode = new node(data);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
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

void triplet(node* n1, node* n2, node* n3, int target) {
    for (node* a = n1; a != nullptr; a = a->next) {
        for (node* b = n2; b != nullptr; b = b->next) {
            for (node* c = n3; c != nullptr; c = c->next) {
                if (a->val + b->val + c->val == target) {
                    cout << a->val << " " << b->val << " " << c->val << "\n";
                    return;
                }
            }
        }
    }
}

void freeList(node* head) {
    while (head) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, k;
    cin >> n >> m >> k;

    node *h1 = nullptr, *h2 = nullptr, *h3 = nullptr;
    node *t1 = nullptr, *t2 = nullptr, *t3 = nullptr;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertAtTail(h1, t1, val);
    }
    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        insertAtTail(h2, t2, val);
    }
    for (int i = 0; i < k; i++) {
        int val;
        cin >> val;
        insertAtTail(h3, t3, val);
    }

    int target;
    cin >> target;

    triplet(h1, h2, h3, target);

    freeList(h1);
    freeList(h2);
    freeList(h3);
    return 0;
}