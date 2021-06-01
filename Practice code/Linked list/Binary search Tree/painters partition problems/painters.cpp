#include<iostream>
using namespace std;

int findfeasible(int boards,int n,int limits){
    int sum = 0,painters = 1;
    for(int i=0;i<n;i++){
        sum += boards[i];
        if(sum > limits){
            sum = boards[i];
            painters++;
        }
    }
    return painters;
}

int painterspartition(int boards[],int n,int m){
    int totallenght = 0,k = 0;
    for(int i=0;i<n;i++){
        k = max(k,boards[i]);
        totallenght += boards[i];
    }

    int low = k, high = totallenght;
    while(low<high){
        int mid = (low+ high)/2;
        int painters = findfeasible(boards,n,mid);
        if(painters <= m){
            high = mid;
        }else{
            low = mid + 1;
        }
    }

    return low;
}

int main()
{
    int arr[] = {10,20,30,40};
    int n = 4;
    int m = 2;

    cout << "MInimun time paint boards : " << painterspartition(arr,n,m);
    cout << endl;
    return 0;
}