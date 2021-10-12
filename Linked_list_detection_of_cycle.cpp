#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class node {
public:
	int data;
	node* next;
	node(int val) {
		data = val;
		next = NULL;
	}
};

//Insert a element in the last of linked list
void insertAtTail(node* &head, int val) {
	node* n = new node(val);
	if (head == NULL) {
		head = n;
		return;
	}
	node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = n;
}

//Display linked list
void display(node* head) {
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

// Making a cycle in linked list
void makecycle(node* &head, int pos)
{
	node* temp = head;
	node* startNode;

	int count =1;
	while(temp->next != NULL){
		if(count==pos){
			startNode = temp;
		}
		temp = temp->next;
		count++;
	}

	temp->next = startNode;
}

//Find the linked list cycle is not?
bool detectedcycle(node* &head){
	node* slow = head;
	node* fast = head;

	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow==fast){
			return true;
		}
	}
	return false;
}

//Remove the cycle from linked list
void removecycle(node* head)
{
	node* slow = head;
	node* fast = head;

	do{
		slow = slow->next;
		fast = fast->next->next;
	}while(slow!=fast);

	fast = head;
	while(fast->next != slow->next)
	{
		slow = slow->next;
		fast = fast->next;
	}

	slow->next = NULL;
}

int main()
{
	node* head = NULL;
	insertAtTail(head, 1);
	display(head);
	insertAtTail(head, 2);
	display(head);
	insertAtTail(head, 3);
	display(head);
	insertAtTail(head, 4);
	display(head);
	insertAtTail(head, 5);
	display(head);
	insertAtTail(head, 6);
	display(head);

	makecycle(head,3);
	// display(head);
	cout<<detectedcycle(head)<<endl;

	removecycle(head);
	cout<<detectedcycle(head)<<endl;
	display(head);


	return 0;
}