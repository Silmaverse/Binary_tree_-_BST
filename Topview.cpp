#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
static int idx = -1;
Node *buildTree(vector<int> preorder)
{
    idx++;
    if (preorder[idx] == -1)
    {
        return NULL;
    }
    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}
// preorder
void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
};
//top view
void topview(Node *root){
    queue<pair<Node *, int>> q;
    map<int, int> m;
    q.push({root, 0});
    while(q.size()>0){
        Node *curr = q.front().first;
        int HD = q.front().second;
        q.pop();
        if(m.find(HD)==m.end()){
            m[HD] = curr->data;
        }
        if(curr->left!=NULL){
            q.push({curr->left, HD - 1});

        }
        if (curr->right != NULL)
        {
            q.push({curr->right, HD +1});
        }
    }

    for(auto it:m){
        cout << it.second << " ";
    }
}

int main(){
   vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
   Node *root = buildTree(preorder);
   topview(root);
   return 0;
 }