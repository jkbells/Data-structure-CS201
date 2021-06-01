#include<iostream>
#include<stack>
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

void zigzagtraversal(Node* root){
    if(root == NULL){
        return;
    }
    stack<Node*> currlevel;
    stack<Node*> nextlevel;

    bool lefttoright = true;
    currlevel.push(root);
    while(!currlevel.empty()){
        Node* temp = currlevel.top();
        currlevel.pop();

        if(temp){
            cout << temp->data << " ";
        

        if(lefttoright){
            if(temp->left){
                nextlevel.push(temp->left);
            }
            if(temp->right){
                nextlevel.push(temp->right);
            }
        }

        // Right to left
        else{
            if(temp->right){
                nextlevel.push(temp->right);
            }
            if(temp->left){
                nextlevel.push(temp->left);
            }
        }
      }
      if(currlevel.empty()){
          lefttoright = !lefttoright;
          swap(currlevel,nextlevel);
      }
    }
}

int main()
{
    /*
           
           12
          /  \
         9    15
        / \
       5   10

    */
    
    Node* root = new Node(12);
    root->left = new Node(9);
    root->right = new Node(15);
    root->left->left = new Node(5);
    root->left->right = new Node(10);

    // test
    zigzagtraversal(root);
    cout << endl;

    return 0;
}

