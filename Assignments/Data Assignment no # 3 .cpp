# Question no # 2

//Reverse a doubly linked list
#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
    int data;
    struct node *nptr; 
    struct node *pptr; 
};

struct node* hptr=NULL; 

void insertNode(int pos, int x)
{
    struct node *temp=new node;
    if(temp==NULL)
        cout<<"Insertion not possible\n";
    temp->data=x;
if(pos==1 && hptr==NULL)
    {
        temp->pptr=NULL;
        temp->nptr=NULL;
        hptr=temp;
    }
    else if(pos==1)
    {
        temp->nptr=hptr;
        hptr=temp;
        temp->nptr->pptr=temp;
        temp->pptr=NULL;
    }
    else
    {
        int i=1;
        struct node *thptr=hptr;
        while(i<pos-1)
        {
            thptr=thptr->nptr;
            i++;
 }
        temp->nptr=thptr->nptr;
        temp->pptr=thptr;
        thptr->nptr=temp;
        thptr->nptr->pptr=thptr;
    }
}

void deleteNode(int pos)
{
    if(hptr==NULL)
        cout<<"Deletion not possible\n";
    else
    {

        if(pos==1)
 {
            hptr=hptr->nptr;
        }
        else
        {
            int i=1;
            struct node *thptr=hptr;
            while(pos<i-1)
            {
                thptr=thptr->nptr;
            }
            thptr->nptr=thptr->nptr->nptr;
            if(thptr->nptr!=NULL)
                thptr->nptr->pptr=thptr;
        }

    }
}

void reverseList()
{
    struct node *current=hptr;
    struct node *prev=NULL;
    while(current!=NULL)
    {
        current->pptr=current->nptr; 
        current->nptr=prev;          
        prev=current;                
        current=current->pptr;       
	}
        hptr=prev;
}

void print()
{
    struct node *thptr=hptr;
    while(thptr!=NULL)
    {
 cout<<thptr->data<<"\n";
        thptr=thptr->nptr;
    }
}

int main()
{
    insertNode(1,11);
    insertNode(2,12);
    insertNode(3,13);
    insertNode(4,14);
    insertNode(5,15);
    reverseList();
    print();
    return 0;
}
            
            
            
# Question no # 2

#include <bits/stdc++.h>
using namespace std;
class Stack 
{ 
    public:
    int top; 
    unsigned capacity; 
    int* array; 
}; 

Stack* createStack( unsigned capacity ) 
{ 
    Stack* stack = new Stack();
  
    if (!stack) return NULL; 
  
    stack->top = -1; 
    stack->capacity = capacity; 
    stack->array = new int[(stack->capacity * sizeof(int))]; 
  
    if (!stack->array) return NULL; 
  
    return stack; 
} 
  
int isEmpty(Stack* stack) 
{ 
    return stack->top == -1 ; 
} 
  
int peek(Stack* stack) 
{ 
    return stack->array[stack->top]; 
} 
  
int pop(Stack* stack) 
{ 
    if (!isEmpty(stack)) 
        return stack->array[stack->top--] ; 
    return '$'; 
} 
  
void push(Stack* stack,int op) 
{ 
    stack->array[++stack->top] = op; 
} 
int evaluatePostfix(char* exp) 
{ 
    Stack* stack = createStack(strlen(exp)); 
    int i; 
    if (!stack) return -1; 
    for (i = 0; exp[i]; ++i) 
    {  
        if(exp[i] == ' ')continue; 
        else if (isdigit(exp[i])) 
        { 
            int num=0; 
            while(isdigit(exp[i])) 
            { 
            num = num * 10 + (int)(exp[i] - '0'); 
                i++; 
            } 
            i--; 
            push(stack,num); 
        } 
        else
        { 
            int val1 = pop(stack); 
            int val2 = pop(stack); 
              
            switch (exp[i]) 
            { 
            case '+': push(stack, val2 + val1); break; 
            case '-': push(stack, val2 - val1); break; 
            case '*': push(stack, val2 * val1); break; 
            case '/': push(stack, val2/val1); break; 
              
            } 
        } 
    } 
    return pop(stack); 
} 

int main() 
{ 
    char exp[] = "100 200 + 2 / 5 * 7 +"; 
    cout << evaluatePostfix(exp); 
    return 0; 
} 
