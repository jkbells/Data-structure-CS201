#include<iostream>
using namespace std;
class list
{
		private:
			char *arr;
            char *n,*empty;
			int counter;
	public:

		int len;
	list()
	    	{
				counter =0;
				cout<<"enter the length =";
				cin>>len;
				arr = new char[len];
				n = arr;
				empty = arr;
				
				for(int i = 0;i<len;i++)
				{
					*empty = '0';
					empty++;
				}
				
			}
	void print()
			{
				empty = arr;
				for(int i=0;i<len;i++)
				{
					cout<<*empty<<" ";
					empty++;
				}
				cout<<endl;
			}
	void insert(char ch)
			{
				empty= arr;
				empty= empty + counter;
				*empty = ch;
				counter++;
				
			}
	void Delete(int pos)
			{
				empty = arr;
				empty = empty + (pos - 1);
				*empty = '0';
				int n = len- pos;
				char *empty1;
				empty1 = empty + 1;
				for(int i = 0;i<n;i++)
				{
					*empty = *empty1;
					empty++;
					empty1++;
				}
				*empty = '0';
				counter--;	
			}
	void update(int pos,char ch)
			{
				empty = arr;
				empty = empty +(pos - 1);
				*empty = ch;
			}
	void search(char ch)
			{
				empty = arr;
				for(int i = 0;i<len;i++)
				{
					if(*empty == ch)
					{
						cout<<ch<<" is found"<<endl;
						return;
					}
					empty++;
				}
				cout<<ch<<"  is not found"<<endl;
				
			}
	void reverse()
			{
				empty = arr;
				char *empty,*empty1;
				empty1 = empty + (counter - 1);
				int n;
				n = counter/2;
				int a=counter-1;
				for(int i = 0;i<n;i++)
				{
					*empty2 = *empty;
					*empty = *empty1;
					*empty1 = *empty2;
					empty=empty+1;
					a--;
					empty1=arr+a;
				}	
			}
};
int main()
{
	list o;
	char o1;
	for(int i = 0;i<o.len;i++)
	{
		cout<<"enter element  :  ";
		cin>>o1;
		o.insert(o1);
	}
	cout<<endl;
	o.print();
	cout<<endl;
	int index;
	cout<<"enter position you  delete :  ";
	cin>>index;
	o.Delete(index);
	o.print();
	cout<<"enter your  position want to change:";
	cin>>index;
	cout<<"enter character:";
	cin>>o1;
	o.update(index,o1);
	o.print();
	cout<<"enter element  to search:";
	cin>>o1;
	o.search(o1);
	o.print();
	cout<<endl;
	o.reverse();
	o.print();
	return 0;
}
