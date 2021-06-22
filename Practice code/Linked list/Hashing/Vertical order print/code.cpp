// print vertical order of a binary tree

#include<iostream>
using namespace std;
#include<map>
#include<unordered_map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>

// #define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

struct Node{
    int key;
    Node *left,*right;
};

Node *newNode(int key)
{
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node; 

}

void getverticalorder(Node* root,int hdis,map<int,vi> &m){
    if(root == NULL){
        return;
    }

    m[hdis].push_back(root->key);
    getverticalorder(root->left,hdis-1,m);
    getverticalorder(root->right,hdis+1,m);
    
}


signed main()
{
    Node* root = newNode(10);
    root->left = newNode(7);
    root->right = newNode(4);
    root->left->left = newNode(3);
    root->left->left = newNode(11);
    root->right->left = newNode(14);
    root->right->right = newNode(6);

    map<int,vector<int> > m;
    int hdis = 0;
    getverticalorder(root,hdis,m);

    map<int,vi> :: iterator it;

    for(it=m.begin();it!=m.end();it++)
    {
        for(int i=0;i<(it->ss).size();i++){
            cout << (it->ss )[i] << " ";
        }
        cout << endl;
    }
    return 0;
}