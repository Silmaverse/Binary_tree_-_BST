#include <iostream>
#include<vector>
using namespace std;

class Node{
 public:

    int data;
    Node *left;
    Node *right;
   Node(int val){
       data = val;
       left = right = NULL;
   }
};
Node *insert(Node*root,int data){
    if(root==NULL){
        return new Node(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }else{
        root->right = insert(root->right, data);
    }
}
Node* BuildBst(vector<int> arr){
    Node *root = NULL;
    for(int val:arr){
        root = insert(root, val);
    }
    return root;
}
// inorder

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
};
//search
bool search(Node *root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }if(root->data<key){
        return search(root->right,key);
    }else{
        return search(root->left, key);
    }
}
//delete Node
Node *getInorder(Node *root){
    while(root->left!=NULL &&root->right!=NULL){
        root = root->left;
    }
    return root;
}
Node *deleteNode(int key, Node *root)
{
    if(root==NULL){
        return NULL;
    }
    if(root->data<key){
        root->right = deleteNode(key, root->right);
    }
    else if(root->data>key){
        root->left = deleteNode(key, root->left);
    }else{
        if(root->left==NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }else if(root->right==NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }else{
            Node *IS = getInorder(root->right);
            root->data = IS->data;
            root->right = deleteNode(IS->data, root->right);
        }
    }

    return root;
}
int main(){
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node* root=BuildBst(arr);
    cout << "Before :";
    inOrder(root);
    cout << endl;
    cout<<search(root, 8);
    deleteNode(6, root);
    cout << "After :";
    inOrder(root);
    return 0;
}