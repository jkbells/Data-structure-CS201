 #include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

/*

       1
      /  \
     2    3
    / \  / \
   4   5 6  7
*/

int calHeight(Node *root){
    int lHeight = calHeight(root->left);
    int rHeight = calHeight(root->right);
    return max(lHeight,rHeight)+1;
}

int height(Node *root){
    if(root == NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh,rh) + 1;
}

bool isbalanced(Node *root){
    if(root == NULL){
        return true;
    }
    if(isbalanced(root->left) == false) {
        return false;
    }

    if(isbalanced(root->right) == false){
        return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh-rh) <= 1){
        return true;
    }
    else{
        return false;
    }

}

/*

       1
      /  \
     2    3
    / \  / \
   4   5 6  7
*/

int calHeight(Node *root){
    if(root == NULL){
        return 0;
    }
    int lHeight = calHeight(root->left);
    int rHeight = calHeight(root->right);
    return max(lHeight,rHeight)+1;
}

int calHeight(Node *root){
    if(root == NULL){
        return 0;
    }

    return max(calHeight(root->left),calHeight(root->right)) + 1;
}

int calDiameter(Node *root){
    if(root == NULL){
        return 0;
    }
    int lHeight = calHeight(root->left);
    int rHeight = calHeight(root->right);
    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = calDiameter(root->left);
    int rDiameter = calDiameter(root->right);

    return max(currDiameter, max(lDiameter,rDiameter));
}


int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Not balanced

 /*
            1
           /
          2
         /
        3
 */ 

    // Node *root2 = new Node(1);
    // root2->left = new Node(2);
    // root2->left->left = new Node(3);

    // // height balance tree
    // if(isbalanced(root))
    // {
    //     cout << "Balanced tree " << "\n";
    // }
    //     else
    //     {
    //         cout << "unbalanced tree" << "\n";       
    //     }

    // if(isbalanced(root2))
    // {
    //     cout << "Balanced tree " << "\n";
    // }
    //     else
    //     {
    //         cout << "unbalanced tree" << "\n";       
    //     }
    
    // Height of binary tree
    cout << calHeight(root) << " \n";
    cout << calDiameter(root) << "\n";

    
    return 0;
}