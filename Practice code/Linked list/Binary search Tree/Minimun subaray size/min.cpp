#include<iostream>
#include<climits>
using namespace std;

int smallestsubarraywithsum(int arr[],int n,int x){

    int sum = 0,minlenght = n+1,start = 0,end = 0;
    while(end < n){
        while(sum <= x && end < n){
            sum += arr[end++];
        }

        while(sum > x && start < n){
            if(end - start < minlenght){
                minlenght = end - start;
            }
            sum -= arr[start++];
        }
    }

    return minlenght;
}


int main()
{
    int arr[] = {1,4,45,6,10,19};
    int x = 51;
    int n = 6;

    int minlenght = smallestsubarraywithsum(arr,n,x);

    if(minlenght == n+1){
        cout << "no such subarray exists" << endl;
    }else{
        cout << "smallest lenght subarray is :" << minlenght << endl;
    }
    return 0;
}



