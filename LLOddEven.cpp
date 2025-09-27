using namespace std;
#include <bits/stdc++.h>

class node {
   public:
    int val;
    node *next;
    node() {
        this->val = 0;
        this->next = nullptr;
    }
    node(int data) {
        this->val = data;
        this->next = nullptr;
    }
};

class linkedList {
    node *head, *tail;

   public:
    linkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insertAtTail(int data) {
        node *newNode = new node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList() {
        node *temp = head;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void seggregate() {
        if (!head) return;

        node *oddHead = nullptr, *oddTail = nullptr;
        node *evenHead = nullptr, *evenTail = nullptr;

        node *curr = head;
        while (curr) {
            if (curr->val % 2 != 0) {
                if (!oddHead) {
                    oddHead = oddTail = curr;
                } else {
                    oddTail->next = curr;
                    oddTail = oddTail->next;
                }
            } else {
                if (!evenHead) {
                    evenHead = evenTail = curr;
                } else {
                    evenTail->next = curr;
                    evenTail = evenTail->next;
                }
            }
            curr = curr->next;
        }

        if (oddTail) {
            oddTail->next = evenHead;
        }
        if (evenTail) {
            evenTail->next = nullptr;
        }

        head = oddHead ? oddHead : evenHead;
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    linkedList l;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        l.insertAtTail(x);
    }

    l.seggregate();
    l.printList();
    return 0;
}