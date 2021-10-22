#include <iostream>
using namespace std;
struct node{
    int data;
    node *ptr,*pre;
};
node *head=NULL;
void insertathead(int a){
    node *temp=new node;
    temp->data=a;
    temp->ptr=temp->pre=temp;
    if(head==NULL)
        head=temp;
    else{
        temp->ptr=head;
        temp->pre=head->pre;
        head->pre=temp;
        temp->pre->ptr=temp;
        head=temp;
    }
}
void deletionathead(){
    if(head==NULL)
        cout<<"EMPTY\n";
    else{
    node *p=head;
        if(head->ptr==head)
            head=NULL;
        else{
            head->pre->ptr=head->ptr;
            head->ptr->pre=head->pre;
            head=head->ptr;
        }
        p=NULL;
    }
}
void display(){
    node *p=head;
    while(p->ptr!=head){
        cout<<p->data<<endl;
        p=p->ptr;
    }
    cout<<p->data<<endl;
}
int main()
{
    insertathead(50);
    insertathead(40);
    insertathead(30);
    insertathead(20);
    insertathead(10);
    display();
    cout<<"After Deletion\n";
    deletionathead();
    deletionathead();
    display();
    return 0;
}
