#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

class DoublyLinkedList
{
public:

    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertStart(int data);
    void insertEnd(int data);
    void insertAfter(int data, int position);
    void insertBefore(int data, int position);
    void remove(int position);
    void display();

private:
    Node *head;
    Node *tail;
    int size;
};

DoublyLinkedList::DoublyLinkedList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

DoublyLinkedList::~DoublyLinkedList()