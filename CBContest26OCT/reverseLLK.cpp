#include <iostream>
using namespace std;

class node{
	public:
		node* next;
		int data;
		node(int data){
			this->data =data;
			this->next = nullptr;
		}
};

void insertAtTail(node *& head, node*& tail, int val){
	node* newNode = new node(val);
	if(!head){
		head = tail = newNode;
	}
	else{
		tail->next = newNode;
		tail = newNode;
	}
}

node* reverseK(node* head, int k){
	if(!head) return nullptr;

	node* curr = head;
	node* prev = nullptr;
	node* next = nullptr;
	int count = 0;

	while(curr != nullptr && count<k){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}

	if(next!=nullptr){
		head->next = reverseK(next , k);
	}

	return prev;
}

void printList(node* head){
	if(!head) return;
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

int main(){
	int n, k;
	cin>>n>>k;
	node* head = nullptr;
	node* tail = nullptr;

	for(int i =0;i<n;i++){
		int val;
		cin>>val;
		insertAtTail(head, tail, val);
	}

	node* reversedList = reverseK(head, k);
	printList(reversedList);

}