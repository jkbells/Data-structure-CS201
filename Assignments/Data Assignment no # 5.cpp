#include<iostream>
using namespace std;


class hash_table{

	int *arr,*arr2;
	bool chkArr,chkArr2;
	int max,len,loc,mod;
	double per;

public:

	hash_table(){
	
		arr=NULL;
		arr2=NULL;
		chkArr=0;
		chkArr2=0;
		max=0;
		len=0;
		loc=-1;
		mod=0;
		per=0.0;
	}

	void create_table(){
	
		cout<<"Enter number of maximum entries: ";
		cin>>max;
		mod=max;
		arr=new int[max];
		chkArr=1;
		for(int i=0;i<max;i++){
		arr[i]=-1;
		}
		
	}


	void create_table(int mod){
	
		
			arr2=new int[mod];
			chkArr2=1;
			chkArr=0;
			for(int i=0;i<mod;i++){
			arr2[i]=-1;
			}

	}

	void insert(int num){
	
		if(len==max){
		
			cout<<"Number of entries complete"<<endl;
			return;
		
		}

		if(chkArr){
		if (arr == NULL){
		
			create_table();

		}

		loc = num % max;
	
		if(arr[loc]==-1){
		
			arr[loc]=num;
			len++;

			per=len/max*100;

			if(per >= 50.0){
			
				rehash();
				
			}
			return;
		
		}

		if(arr[loc] != -1){
		
			int i=loc+1;
			while(i != loc ){
			
				if(arr[i] == -1){
				
					arr[i]=num;
					len++;
					
					per=len/max*100;

					if(per >= 50.0){
			
						rehash();
					}
					return;
				
				}
			
				
				if(i==mod-1){
				
					i=0;
				}
				else i++;
			}
		
		}
		}

		//insertion for arr2 pointer
		else{
		
		
			loc = num % max;
	
		if(arr2[loc]==-1){
		
			arr2[loc]=num;
			len++;

			
			return;
		
		}

		if(arr2[loc] != -1){
		
			int i=loc+1;
			while(i != loc ){
			
				if(arr2[i] == -1){
				
					arr2[i]=num;
					len++;
					
					return;
				
				}
			
				
				if(i==mod-1){
				
					i=0;
				}
				else i++;
			}
		
		}
		}
		
		
		
		
	}//insertion

	//

	void rehash(){
	
		mod*=2;
		create_table(mod);
		
		for(int i=0; i< mod/2;i++ )
		{
		
			if(arr[i] != -1){
			
				loc=arr[i] % mod;
				
				if(arr2[loc] == -1){
					
					arr2[loc] = arr[i]; 

				}

				else {
				
				int j=loc+1;
				while(j != loc ){
			
				if(arr2[j] == -1){
				
					arr2[j]=arr[i];
				
				}
			
				
				if(j==mod-1){
				
					j=0;
				}

				else j++;
				}
					
				}
		
			}
		
		}
	}// rehash

	//------------------SEARCH-----------------------

	bool search (int num){

		if(len == 0){
		
			cout<<"Table is empty "<<endl;
			return 0;
		}

		loc=num % mod;

		if(arr[loc]  != -1 ){


		if(arr[loc]==num){
		
			return 1;
		
		}

		else {
		int i=loc+1;

		while( i != loc){
		
			if(arr[i] == -1){
			
				return 0;
			}
			
			if(arr[i] == num){
			
				return 1;
			}

			i++;
			if(i == mod-1){
			
				i=0;
			}
		}//while
			
		}

		}// main if

		else {

			return 0;
		}

	}// function end
};

int main(){
    hash_table a;
    // a.create_table();
    // a.create_table(5);
    // a.insert(13);
	// a.insert(24);
	// a.insert(23);
	// a.insert(34);
	// a.insert(50);
    // a.rehash();
    // a.search(2);
	return 0;
}