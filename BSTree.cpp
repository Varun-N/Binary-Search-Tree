#include "BSTree.h"

#include <iostream>

using namespace std;

///////////////////////////////////
// Already Implemented Functions //
///////////////////////////////////

// These functions are already implemented for you. Scroll below to
// see the functions that you have to implement 


// constructors
BSTree::BSTree() : size(0), root(nullptr) {}

// input / output operators
ostream& operator<<(ostream& out, BSTree& tree)
{
    tree.print_level_by_level(out);
    return out;
}

ostream& operator<<(ostream& out, Node& node)
{
    return out << node.value << "[" << node.search_time << "]";
}

istream& operator>>(istream& in, BSTree& tree)
{
    /*
      take input from the in stream, and build your tree
      input will look like
      4 
      2 
      6 
      1 
      3 
      5 
      7
    */
    int next;
    while(in >> next) {
        tree.insert(next);
    }
    return in;
}

// Example recursive function
void BSTree::copy_helper(Node*& newNode, const Node* sourceNode) {
    //Don't copy if the node is nullptr
    if(sourceNode == nullptr)
        return;

    //Change the new node to a copy of sourceNode
    newNode = new Node(sourceNode->value);
    //Copy over the search cost
    newNode->search_time = sourceNode->search_time;

    //Copy left subtree
    if (sourceNode->left != nullptr)
        copy_helper(newNode->left, sourceNode->left);
    //Copy right subtree
    if(sourceNode->right != nullptr)
        copy_helper(newNode->right, sourceNode->right);
}

// recursive function
int BSTree::get_total_search_time(Node* node)
{
  if (node != nullptr) {
    return node->search_time + get_total_search_time(node->left) + get_total_search_time(node->right);
  }
  return 0;
}

// implemented
float BSTree::get_average_search_time()
{
  int total_search_time = get_total_search_time(root);
  if(total_search_time == 0)
    return -1;
	
  return ((float)total_search_time)/size;
}


///////////////////////////////////
//     Functions to Implement    //
///////////////////////////////////

// These are the functions you should implement
// Feel free to call the functions above or create new helper functions

// copy constructor
BSTree::BSTree(const BSTree& other)
{
  copy_helper(this->root, other.root);
}

// move constructor
BSTree::BSTree(BSTree&& other){
  this->root = other.root;
  other.root = NULL;
}

//copy assignment
BSTree& BSTree::operator=(const BSTree& other)
{
  if(this != &other)
    {
        this->deleteNode(); //oof
        Node *c = other.root;
        copyassignment_helper(c);
    }
    return *this;
}

// struct node* deleteNode(struct Node* root, int key) 
// { 
//     // base case 
//     if (root == NULL) return root; 
  
//     // If the key to be deleted is smaller than the root's key, 
//     // then it lies in left subtree 
//     if (key < root->value) 
//         root->left = deleteNode(root->left, key); 
  
//     // If the key to be deleted is greater than the root's key, 
//     // then it lies in right subtree 
//     else if (key > root->key) 
//         root->right = deleteNode(root->right, key); 
  
//     // if key is same as root's key, then This is the node 
//     // to be deleted 
//     else
//     { 
//         // node with only one child or no child 
//         if (root->left == NULL) 
//         { 
//             struct node *temp = root->right; 
//             free(root); 
//             return temp; 
//         } 
//         else if (root->right == NULL) 
//         { 
//             struct node *temp = root->left; 
//             free(root); 
//             return temp; 
//         } 
  
//         // node with two children: Get the inorder successor (smallest 
//         // in the right subtree) 
//         struct node* temp = minValueNode(root->right); 
  
//         // Copy the inorder successor's content to this node 
//         root->key = temp->key; 
  
//         // Delete the inorder successor 
//         root->right = deleteNode(root->right, temp->key); 
//     } 
//     return root; 
// } 

void BSTree::copyassignment_helper(Node *c)
{
    if (c != nullptr)
    {
        this->insert(c->value);
        copyassignment_helper(c->left);
        copyassignment_helper(c->right);
    }
}

// move assignment
BSTree& BSTree::operator=(BSTree&& other){

}

// destructor
BSTree::~BSTree()
{
    // Make sure to call delete on every node of the tree
    // You can use a recursive helper function to do this
    destructor_helper(root);
}

void BSTree::destructor_helper(Node* node){
    if (node != NULL) {
      if (node->right != NULL) {
        destructor_helper(node->right);
      }
      if (node->left != NULL) {
        destructor_helper(node->left);
      }
      delete node;
    }
}

Node* BSTree::insert(int obj)
{
    /* insert a node into the tree
    first find where the node should go
    then modify pointers to connect your new node */
}

// void insert_helper(Node* obj){

// }

Node* BSTree::search(int obj)
{
    /* recursively search down the tree to find the node that contains obj
    if you don't find anything return nullptr */
    if (root == NULL || root->value == obj) 
       return root; 
     
    // Key is greater than root's key 
    if (root->value < obj) 
       return search(root->right->value); 
  
    // Key is smaller than root's key 
    return search(root->left->value);
}

void BSTree::update_search_times()
{
    /* do a BFS or DFS of your tree and update the search times of all nodes at once
      The root has a search time of 1, and each child is 1 more than its parent */
}

void BSTree::inorder(ostream& out)
{
    /* print your nodes in infix order
    If our tree looks like this:

       4
     2   6
    1 3 5 7

    It should output:
    1[3] 2[2] 3[3] 4[1] 5[3] 6[2] 7[3]
    You can use the << operator to print the nodes in the format shown */
}

void BSTree::print_level_by_level(ostream& out)
{
    /* Print the tree using a BFS so that each level contains the values for a level of the tree.
    Use X to mark empty positions. 
    
      if our tree looks like this:

       4
     2   6
    1   5 7
           9

    it should output:

    4[1]
    2[2] 6[2]
    1[3] X 5[3] 7[3]
    X X X X X X X 9[4]

    it might be helpful to do this part with the std::queue data structure.
    Hint: the Nth level contains 2^(N-1) nodes (with a value or with an X). Watch out
    for nodes like the left child of 6 above, and print the descendents of an empty
    node as also empty
    You can use the << operator to print nodes in the format shown */
}
