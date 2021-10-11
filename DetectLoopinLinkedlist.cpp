//C++ program to detect loop in linkedlist using floyd's cycle finding algorithm
#include <bits/stdc++.h>
using namespace std;
 
/* Link list node */
class Node {
public:
    int data;
    Node* next;
};
 
void push(Node** head_ref, int new_data)
{
    
    Node* new_node = new Node();
    
    new_node->data = new_data;
    
    new_node->next = (*head_ref);
 
    (*head_ref) = new_node;
}
 
int detectLoop(Node* head)
{
    Node *fast_pointer = head;
    Node *slow_pointer = head;

  while(fast_pointer && fast_pointer->next)
  {
    slow_pointer = slow_pointer->next;
    fast_pointer = fast_pointer->next->next;
    if(fast_pointer == slow_pointer)
    {
      return 1;
    }
  }

  return 0;
}
 

int main()
{
    /* Start with the empty list */
    Node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 15);
    push(&head, 10);
 
    /* Create a loop for testing */
    head->next->next->next = head;
    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
    return 0;
}