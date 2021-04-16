#include<iostream>
using namespace std;

struct node{
int value;
node *next,*previous;
};



class DRL{
private:
	node *head,*temp,*temp2;
public:
	DRL(){
	head=temp=temp2=NULL;
	}

	void add(){

		
		if(head==NULL){
		head=new node;
		cin>>head->value;
		head->next=head->previous=head;
		temp=head;
		return;
		}

		

		temp=new node;
		cin>>temp->value;
		temp->previous=head->previous;
		temp->next=head;
		head->previous=temp;
		temp->previous->next=temp;
		
		

	}


	void addAV(int num){
		
		if(head==NULL){
		cout<<"List is Empty..."<<endl;
		return;
		}

	temp=head;
	
		
	do{
	
		
	if(temp->value==num){
		temp2=new node;
		cin>>temp2->value;
		temp2->next=temp->next;
		temp->next=temp2;
		temp2->previous=temp;
		temp2->next->previous=temp2;
		
		break;
	}
	

	temp=temp->next;
	}while(temp!=head);

	}


	void deletFirst(int num){
	
		if(head==NULL){
		cout<<"List is Empty"<<endl;
		return;
		}

		temp=head;

		

		do{
		
			if (temp->value==num){
		
			if(temp->next!=temp){	
			temp->previous->next=temp->next;
			temp->next->previous=temp->previous;
			if(temp==head){
			head=head->next;
			}
			}
			else{
			
			head=NULL;
			}

			delete temp;
			break;
			}

		temp=temp->next;
		}while(temp!=head);
	}




	void print(){
	temp=head;

	if(head==NULL){
	cout<<"Array is empty"<<endl;
	return;
	}
	cout<<"\n";

	do{
	cout<<temp->value<<endl;
	temp=temp->next;
	
	

	}while(temp!=head);

	}

};

int main(){

	DRL obj;

	obj.add();//1
	obj.add();//2
	obj.add();//3
	obj.add();//4
	cout<<"\nAfter 1"<<endl;
	obj.addAV(1);//5
	cout<<"\nAfter 4"<<endl;
	
	obj.addAV(4);
	cout<<"\nAfter 3"<<endl;
	
	obj.addAV(3);
	obj.print();

	obj.add();//6   Yahan pr error da ga
	cout<<endl;
	
	obj.print();
	
	obj.deletFirst(3);
	obj.print();

	obj.deletFirst(1);
	obj.print();

	obj.deletFirst(5);

	obj.print();

	obj.deletFirst(6);	
	obj.print();


	obj.add();
	obj.print();

	obj.addAV(4);//5
	obj.print();

	return 0;
}
