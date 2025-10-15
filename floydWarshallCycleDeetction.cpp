#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

Node* CycleDetection(Node *head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return slow;
        }
    }
    return nullptr;
}

Node *findStart(Node *head, Node *meet) {
    Node *slow = head, *fast = meet;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}


bool floydCycleRemoval(Node *head) {
    Node *meet = CycleDetection(head);
    if (!meet) return false;
    Node *start = findStart(head, meet);
    Node *temp = start;
    while (temp->next != start) {
        temp = temp->next;
    }
    temp->next = nullptr;
    return true;

}

void buildCycleList(Node *&head) {
    unordered_map<int, Node *> hash;
    int x;
    cin >> x;
    if (x == -1) {
        head = NULL;
        return;
    }
    head = new Node(x);
    hash[x] = head;
    Node *current = head;
    while (x != -1) {
        cin >> x;
        if (x == -1) break;
        if (hash.find(x) != hash.end()) {
            current->next = hash[x];
            return;
        }
        Node *n = new Node(x);
        current->next = n;
        current = n;
        hash[x] = n;
    }
    current->next = NULL;
}

void printLinkedList(Node *head) {
    unordered_set<int> s;
    while (head != NULL) {
        if (s.find(head->data) != s.end()) {
            cout << "\nCycle detected at " << head->data;
            return;
        }
        cout << head->data << " ";
        s.insert(head->data);
        head = head->next;
    }
}

int main() {
    Node *head = NULL;

    buildCycleList(head);

    bool cyclePresent = floydCycleRemoval(head);
    if (cyclePresent) {
        cout << "Cycle was present\n";
    } else {
        cout << "No cycle\n";
    }

    cout << "Linked List - ";
    printLinkedList(head);

    return 0;
}