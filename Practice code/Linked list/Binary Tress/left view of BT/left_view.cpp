#include<iostream>
#include<queue>
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

void leftview(Node *root){
    if(root==NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        for(int i=1;i<=n;i++){
            Node *temp = q.front();
            q.pop();

            if(i == 1){
                cout << temp->data << " ";
            }
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
}
int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);

    leftview(root);
    cout << endl;
    return 0;
}