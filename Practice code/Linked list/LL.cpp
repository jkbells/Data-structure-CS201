#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insertathead(node *&head,int val)
{
    // insert node at the first position of the linked list

    node *n = new node(val);
    n->next = head;
    head = n;
}

void insertattail(node *&head,int val)
{
    // insert node at the end of the linked list

    node *n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next=n;
}

bool search(node *head,int key)
{
    // searching in the linked list

    node *temp = head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteathead(node *&head){

    // delete the node to the head of the linked list
    node *todelete=head;
    head = head->next;
    delete todelete;

}

void deletenode(node *&head,int val){

    // delete the node in the linked list
    if(head == NULL){
        return ;
    }

    if(head->next==NULL){
        deleteathead(head);
        return ;
    }
    node *temp = head;
    while(temp->next->data!=val){
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

void display(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout <<"NULL" <<  endl;
}

node* reverse(node *&head)
{
    node *prevptr= NULL;
    node *currptr = NULL;
    node *nextptr = NULL;   

    while(currptr!=NULL)
    {
        nextptr = currptr->next;
        currptr -> next = prevptr;

        prevptr=currptr;
        currptr=nextptr;

    }
    return prevptr;
}

node *reverserecursive(node *&head)
{

    if(head==NULL || head->next==NULL){
        return head;
    }
    node *newhead = reverserecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

node* reversek(node *&head,int k)
{
    node *prevptr= NULL;
    node *currptr= NULL;
    node *nextptr= NULL;

    int count=0;
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if(nextptr!=NULL){
    head->next = reversek(nextptr,k);
    }
    return prevptr;
}

void makecycle(node *&head,int pos)
{
    node *temp = head;
    node *startnode;

    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startnode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startnode;
}

bool detectcycle(node* &head){
    node *slow=head;
    node *fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast=fast->next->next;

        if(fast==slow){
            return true;
        }
    }
    return false;
}

void removecycle(node *&head)
{
    node *slow=head;
    node *fast=head;

    do{
        slow= slow->next;
        fast=fast->next->next;
    }while(slow!=fast);

    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}

int main()
{
    node *head=NULL;

    // insertattail(head,1);
    // insertattail(head,2);
    // insertattail(head,3);
    // insertathead(head,4);
    // insertattail(head,5);
    // insertattail(head,6);
    // insertattail(head,7);
    // display(head);

    //cout << search(head,2) << endl;
    // deletenode(head,2);
    // deleteathead(head);

    // node *newhead = reverse(head);
     
    // node *newhead = reverserecursive(head);
    // display(newhead);

    // int k=2;
    // node *newhead = reversek(head,k);
    // display(newhead);

    insertathead(head,1);
    insertattail(head,2);
    insertattail(head,3);
    insertattail(head,4);
    insertattail(head,5);
    insertattail(head,6);
    makecycle(head,3);
   // display(head);
   cout << detectcycle(head) << endl;
   removecycle(head);
   cout << detectcycle(head) << endl;
   display(head);

    return 0;
}

