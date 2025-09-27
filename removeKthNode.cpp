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
    node* head, *tail;
public:
    linkedList() {
        head = tail = nullptr;
        length =0;
    }
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

    int lenght(){
        node* dummy= head;
        int length=0;
        while(dummy){
            length++;
            dummy=dummy->next;
        }
        return length;
    }

    node* removeNthNode(int k){
        if(head==nullptr) return head;
        int length = lenght();
        if(k==length){
            node* newHead = head->next;
            delete head;
            return newHead;
        }
        node* fast=head;
        node* slow=head;
        for(int i =0;i<k;i++){
            fast=fast->next;
        }

        while(fast->next!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }
        node* temp=slow->next;
        slow->next=slow->next->next;
        delete temp;
        return head;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    return 0;
}