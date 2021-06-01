#include<iostream>
#include<climits>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* constructBST(int preorder[],int *preorderidx,int key,int min, int max,int n){
    if(*preorderidx >=n){
        return NULL;
    }
    Node* root = NULL;
    if(key > min && key < max){
        root = new Node(key);
        *preorderidx = *preorderidx + 1;

        if(*preorderidx < n){
            root->left = constructBST(preorder,preorderidx,preorder[*preorderidx],min,key,n);
        }
        if(*preorderidx < n){
            root->right = constructBST(preorder,preorderidx,preorder[*preorderidx],key,max,n);
        }
    }
    return root;
}

void printpreorder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data <<  " ";
    printpreorder(root->left);
    printpreorder(root->right);
}

int main(){
    
    /*
           10
           /  \
          2    13
         /     /
        1     11
    */

   int preorder[] = {10,2,1,13,11};
   int n = 5;
   int preorderidx = 0;
   Node* root = constructBST(preorder,&preorderidx,preorder[0], INT_MIN,INT_MAX,n);
   printpreorder(root);
    return 0;
}