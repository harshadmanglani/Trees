#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

class Node
{
    Node *left, *right;
    int data;
    friend class BinarySearchTree;

    public:
    Node(int data)
    {
        this->left = this->right = NULL;
        this->data = data;
    }
};

class BinarySearchTree
{
    Node* root;

    public:
    BinarySearchTree(int data)
    {
        root = new Node(data);
    }


    bool insert(int data);
    bool search(int data);
    void inOrder();
    void inOrderUtil(Node *node);
    void preOrder();
    void preOrderUtil(Node *node);
    void postOrder();
    void postOrderUtil(Node *node);
    void inOrderWithoutRecursion();
    void preOrderWithoutRecursion();
    void postOrderWithoutRecursion();
    void levelOrderTraversal();
    int height();
    int heightUtil(Node *node);
};

bool BinarySearchTree::insert(int data)
{
    Node *node = this->root;
    while(true)
    {
        if(data < node->data)
        {
            if(node->left == NULL)
            {
                node->left = new Node(data);
                break;
            }
            else
            {
                node = node->left;
                continue;
            }
        }
        else
        {
            if(node->right == NULL)
            {
                node->right = new Node(data);
                break;
            }
            else
            {
                node = node->right;
                continue;
            }
        }
    }
    return true;
}
int BinarySearchTree::height()
{
    return heightUtil(root);
}
int BinarySearchTree::heightUtil(Node *node)
{
    if(node == NULL)
            return 0;

        return 1 + max(heightUtil(node->left), heightUtil(node->right));
}
void BinarySearchTree::levelOrderTraversal()
{
    queue<Node*> lOT;
    lOT.push(root);
    cout<<"levelOrderTraversal: ";
    while(!lOT.empty())
    {
        Node *node = lOT.front();
        lOT.pop();
        cout<<" "<<node->data;
        if(node->left != NULL)
            lOT.push(node->left);
        if(node->right != NULL)
            lOT.push(node->right);
    }
}
void BinarySearchTree::postOrderWithoutRecursion()
{
    stack<Node*> postOrder;
    postOrder.push(root);
    map<Node*, bool> left, right;
    cout<<"postOrder: ";
    while(!postOrder.empty())
    {
        Node *node = postOrder.top();
        if(node->left != NULL && left.find(node) == left.end())
        {
            postOrder.push(node->left);
            left.insert({node, true});
            continue;
        }
        if(node->right != NULL && right.find(node) == right.end())
        {
            postOrder.push(node->right);
            right.insert({node, true});
            continue;
        }
        cout<<" "<<node->data;
        postOrder.pop();
    }
}
void BinarySearchTree::preOrderWithoutRecursion()
{
    stack<Node*> preOrder;
    preOrder.push(root);
    map<Node*, bool> left, right, print;
    cout<<"preOrder: ";
    while(!preOrder.empty())
    {
        Node *node = preOrder.top();
        if(print.find(node) == print.end())
        {
            cout<<" "<<node->data;
            print.insert({node, true});
        }
        if(node->left != NULL && left.find(node) == left.end())
        {
            preOrder.push(node->left);
            left.insert({node, true});
            continue;
        }
        if(node->right != NULL && right.find(node) == right.end())
        {
            preOrder.push(node->right);
            right.insert({node, true});
            continue;
        }
        preOrder.pop();
    }
}
void BinarySearchTree::inOrderWithoutRecursion()
{
    stack<Node*> inOrder;
    inOrder.push(root);
    map<Node*, bool> left, right;
    cout<<"inOrder: ";
    while(!inOrder.empty())
    {
        Node *node = inOrder.top();
        if(node->left != NULL && left.find(node) == left.end())
        {
            inOrder.push(node->left);
            left.insert({node, true});
            continue;
        }
        inOrder.pop();
        cout<<" "<<node->data;
        if(node->right != NULL && right.find(node) == right.end())
        {
            inOrder.push(node->right);
            right.insert({node, true});
            continue;
        }
    }
}
bool BinarySearchTree::search(int data)
{
    Node *node = this->root;
    while(data != node->data)
    {
        if(data < node->data)
        {
            if(node->left == NULL)
                return false;
            else
            {
                node = node->left;
                continue;
            }
        }
        else
        {
            if(node->right == NULL)
                return false;
            else
            {
                node = node->right;
                continue;
            }
        }
    }
    return true;
}
void BinarySearchTree::inOrder()
{
    cout<<"inOrder: ";
    inOrderUtil(root);
}
void BinarySearchTree::inOrderUtil(Node *node)
{
    if(node == NULL)
        return;
    inOrderUtil(node->left);
    cout<<" "<<node->data;
    inOrderUtil(node->right);
}
void BinarySearchTree::preOrder()
{
    cout<<"preOrder: ";
    preOrderUtil(root);
}
void BinarySearchTree::preOrderUtil(Node *node)
{
    if(node == NULL)
        return;
    cout<<" "<<node->data;
    preOrderUtil(node->left);
    preOrderUtil(node->right);
}
void BinarySearchTree::postOrder()
{
    cout<<"postOrder: ";
    postOrderUtil(root);
}
void BinarySearchTree::postOrderUtil(Node *node)
{
    if(node == NULL)
        return;
    postOrderUtil(node->left);
    postOrderUtil(node->right);
    cout<<" "<<node->data;
}

int main()
{
    int searchObject;
    BinarySearchTree obj(10);
    obj.insert(4);
    obj.insert(2);
    obj.insert(8);
    obj.insert(20);
    obj.insert(15);
    obj.insert(40);
    obj.insert(68);
    obj.insert(-5);
    obj.insert(-3);
    obj.inOrder();
    cout<<endl<<endl;
    obj.inOrderWithoutRecursion();
    cout<<endl<<endl<<endl;
    obj.preOrder();
    cout<<endl<<endl;
    obj.preOrderWithoutRecursion();
    cout<<endl<<endl<<endl;
    obj.postOrder();
    cout<<endl<<endl;
    obj.postOrderWithoutRecursion();
    cout<<endl<<endl<<endl;
    obj.levelOrderTraversal();
    cout<<"search for object: ";
    cin>>searchObject;
    cout<<obj.search(searchObject)<<endl<<endl;
    cout<<"height of the binary tree: "<<obj.height()<<endl;
    return 0;
}