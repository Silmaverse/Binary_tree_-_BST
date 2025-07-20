#include <iostream>
#include<vector>
#include<queue>
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
static int idx = -1;
Node *buildTree(vector<int>preorder){
    idx++;
    if(preorder[idx]==-1){
        return NULL;
    }
    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}
//preorder
void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
};

//inorder

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
//postorder
void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
};
//levelorder
void levelOrder(Node *root){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0){
        Node *curr = q.front();
        q.pop();
        if(curr==NULL){
            if(!q.empty()){

                cout << endl;
                q.push(NULL);
                continue;
            }else{
                break;
            }
        }
        cout << curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}
int height(Node * root){
    if(root==NULL){
        return 0;
    }
    int leftht = height(root->left);
    int rightht = height(root->right);

    return max(leftht, rightht) + 1;
}
int countNode(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftcount = countNode(root->left);
    int rightcount = countNode(root->right);

    return leftcount+rightcount+ 1;
}
int sumOfnode(Node * root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftsum = sumOfnode(root->left);
    int rightsum = sumOfnode(root->right);

    return leftsum + rightsum +root->data;
}

int main(){

    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder);
    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    levelOrder(root);
    cout << endl;
    cout << height(root);
    cout << endl;
    cout << countNode(root);
    cout << endl;
    cout << sumOfnode(root);

    return 0;
}