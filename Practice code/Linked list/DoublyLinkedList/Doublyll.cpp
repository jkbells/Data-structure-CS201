#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *prev;
    node *next;
    
    node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }

};

void insertathead(node *&head,int val)
{
    node *n = new node(val);
    n->next = head;
    if(head != NULL)
    {
        head->prev = n;
    }

    head = n;
}

void display(node* head){
    node* temp = head;
    while (temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertattial(node *&head,int val)
{
    if(head==NULL){
        insertathead(head,val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    } 
    temp->next=n;
    n->prev = temp;
}

void deleteathead(node *&head)
{
    node *todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}

void deletion(node *&head,int pos)
{
    if(pos==1)
    {
        deleteathead(head);
        return ;
    }
    node *temp =head;
    int count = 1;
    while(temp!=NULL && count!=pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if(temp->next!=NULL)
    {
        temp->next->prev = temp->prev;   
    }
    delete temp;
}

int length(node *head){
    int l=0;
    node *temp = head;
    while(temp!=NULL){
        l++;
        temp = temp->next;
    }
    return l;
}

node *kappend(node *&head,int k)
{
    node *newhead;
    node *newtail;
    node *tail = head;

    int l= length(head);
    k=k%l;
    int count=1;   

    while(tail->next!=NULL)
    {
        if(count==l-k){
            newtail = tail;
        }
        if(count==l-k+1){
            newhead = tail;
        }
        tail = tail->next;
        count++;
    }
    newtail->next=NULL;
    tail->next=head;

    return newhead;
}

// int length(node *head)
// {
//     int l=0;
//     node *temp = head;
//     while(temp!=NULL)
//     {
//         temp = temp->next;
//         l++;
//     }
//     return l;
// }

void intersect(node *&head1,node *&head2,int pos)
{
    node *temp1=head1;
    pos--;
    while (pos--){
        temp1 = temp1->next;
    }
    node *temp2 = head2;
    while (temp2->next!=NULL)
    {
        temp2=temp2->next;
    }

    temp2->next = temp1;
    
}

int intersection(node *&head1,node *&head2)
{
    int l1=length(head1);
    int l2=length(head2);

    int d=0;
    node *ptr1;
    node *ptr2;

    if(l1>l2){
        d = l2-l1;
        ptr1=head1;
        ptr2 = head2;
    }
    else{
        d = l2-l1;
        ptr1 = head2;
        ptr2=head1;
    }

    while(d){
        ptr1 = ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;

    }

    return -1;
}

node *merge(node *&head1,node *&head2)
{
    node *p1 = head1;
    node *p2 = head2;
    node *dummynode = new node(-1);
    node *p3=dummynode;

    while(p1!=NULL && p2!=NULL){
        if(p1->data<p2->data){
            p3->next=p1;
            p1 = p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while(p1!=NULL){
        p2->next=p1;
        p1=p1->next;
        p3=p3->next;
    }

    while(p2!=NULL){
        p2->next=p2;
        p2=p2->next;
        p3=p3->next;
    }

    return dummynode->next;
}

// through recursion 
node *mergerecursive(node *&head1,node *&head2)
{

    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    node *result;
    if(head1->data<head2->data)
    {
        result = head1;
        result->next = mergerecursive(head1->next,head2);
    }
    else{
        result=head2;
        result->next = mergerecursive(head1,head2->next);
    }

    return result;
}

int main()
{
    //node *head = NULL;
    // insertattial(head,1);
    // insertattial(head,2);
    // insertattial(head,3);
    // insertattial(head,4);
    // // insertattial(head,5);
    // display(head);
    // insertathead(head,5);
    // display(head);
    // deletion(head,1);
    // display(head); 

    // node *head = NULL;
    // int arr[] = {1,2,3,4,5,6};
    // for (int i=0;i<6;i++){
    //     insertattial(head,arr[i]);
    // }
    // display(head);

    // node *newhead = kappend(head,3);
    // display(newhead);


    // node *head1 = NULL;
    // node *head2 = NULL;
    // insertattial(head1,1);
    // insertattial(head1,2);
    // insertattial(head1,3);
    // insertattial(head1,4);
    // insertattial(head1,5);
    // insertattial(head1,6);
    // insertattial(head2,9);
    // insertattial(head2,10);

    // intersect(head1,head2,3);
    // display(head1);
    // display(head2);
    // cout << intersection(head1,head2);

    node *head1=NULL;
    node *head2 = NULL;
    int arr1[] = {1,4,5,7};
    int arr2[] = {2,3,6};

    for (int i=0;i<3;i++){
        insertattial(head1,arr1[i]);
    }

    for (int i=0;i<3;i++){
        insertattial(head2,arr2[i]);
    }

    display(head1);
    display(head2);
    node *newhead = mergerecursive(head1,head2);
    display(newhead);
     

    return 0;
}
