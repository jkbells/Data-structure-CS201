#include<iostream>
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

// isIdentical
bool isidentical(Node *root1,Node *root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }

    else if(root2 == NULL || root2 == NULL){
        return false;
    }

    else
    {
        bool cond1 = root1->data == root2->data;
        bool cond2 = isidentical(root1->left,root2->left);
        bool cond3 = isidentical(root1->right,root2->right);

        if(cond1 && cond2 && cond3){
            return true;
        }
        else{
            return false;
        }
    }
    
}

int main()
{

    /*
               2
              / \
             1   3

    */

    Node *root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);

    /*
           6
          / \ 
         3   10
    
    */

    Node *root2 = new Node(6);
    root2->left = new Node(3);
    root2->right = new Node(10);



    if(isidentical(root,root2)){
        cout << "BSTs are identical" << endl;
    }else{
        cout << "BSTs are not identical" << endl;
    }
    return 0;
}