#include<iostream>
using namespace std;
struct node {
	
	int value;
	node *next;
};
 // create a function doing his three work
 
 node *create_node(node *current ,int new_node_value )
{
	node *n=new node;  // create node;
	// set all the values
	n->value = new_node_value;
	n->next = NULL;
	// link "current" node to this new node 
	current->next = n;
	return n;
}
// output the list by using a function
 
void output_list(node *head)
{
	node *current = head;
	cout << "[";
	while (current!=NULL)
	{
		cout << current->value << "  ";
		current = current->next;
	}
	cout << "]" << endl;
}
// delete the node 
void delete_after_node(node *current)
{
	node *temp = current->next;
	current->next = current->next->next;
	delete temp;
}
int main()
{
	node *head;
	head = new node;
	head->value = 2;
	head->next = NULL;
	
	node *current = head;
	current = create_node(current,27);
	current = create_node(current,30);
	current = create_node(current,50);
	
	output_list(head);
	current = head;
	output_list(head);
	current = head->next;
	cout <<"going to delete" << current->value << endl;
	delete_after_node(head);
	output_list(head);
	system ("pause");
	return 0;
}
