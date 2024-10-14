/*
Alex Cannizzaro
Student ID: 2421315
acannizzaro@chapman.edu
CPSC-350-01
Programming Assignment 5: Lazy BST
Header file for the LazyBST class - contains function declarations and definitions
*/
#ifndef LAZY_BST_H
#define LAZY_BST_H

#include "TreeNode.h"
#include <iostream>
#include <stdexcept>
#include <fstream>

//LazyBST class - an object represents a tree of data that automatically balances itself
template <typename T>
class LazyBST{
    public:
        //default constructor
        LazyBST();

        //default destructor
        virtual ~LazyBST();

        //accessor for m_size member variable
        int getSize();

        //insert method - creates a new node with the given data and puts it in the correct place in the tree
        void insert(T data);

        //remove method - finds node with data that matches the parameter and removes it from the tree
        void remove(T data);

        //returns true if the tree contains a node with data that matches the parameter
        bool contains(T data);

        //prints the contents of the tree in ascending order
        void printTreeInOrder();

        //prints the contents of the tree; children are printed before parents
        void printTreePostOrder();

        //returns the data (type T) with the minimum value in the tree
        T getMin();

        //returns the data (type T) with the maximum value in the tree
        T getMax();

        /*
        Search method - searches the tree for a node with the given data
        if found, returns a pointer to the node; if not, returns a pointer to NULL
        */
        TreeNode<T>* search(T key);

        //prints the contents of the tree to a file in ascending order
        void printToFile(std::string fileName);

    private:
        TreeNode<T>* m_root; //pointer to the root node of the tree
        int m_size;  //the number of nodes in the tree
        int m_currIdx;  //used to keep track of the tree's values (in an array) when balancing
        int m_fillCounter;  //used to keep track of iterations when refilling the tree after balancing
        int m_arrSize;  //keeps track of the tree's size before clearing and rebalancing
        T* m_orderedArr; //array that holds the tree's data (elements of type T) in ascending order
        std::ofstream m_outFS;  //used for outputting to a file

        //helper method - recursively finds the right place to insert a new node
        void insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode);

        //helper method - recursively determines if a certain piece of data exists in the tree
        bool containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode);

        //helper method - recursively prints the tree's nodes in ascending order
        void printTreeInOrderHelper(TreeNode<T>* subTreeRoot);

        //helper method - recursively prints the tree's nodes in post-order format
        void printTreePostOrderHelper(TreeNode<T>* subTreeRoot);

        //helpder method - recursively finds the minimum value in the tree
        T getMinHelper(TreeNode<T>* subTreeRoot);

        //helpder method - recursively finds the maximum value in the tree
        T getMaxHelper(TreeNode<T>* subTreeRoot);

        //helper method - used when removing a node
        void findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent);

        //helper method - finds the successor of a node that will be removed
        TreeNode<T>* getSuccessor(TreeNode<T>* rightChild);

        //returns the greatest depth of the subtree anchored at the given node
        int getMaxDepth(TreeNode<T>* subTreeRoot);

        //checks to see if the tree needs to be rebalanced
        void checkForBalance();

        //rebalances the tree by adding the values to an array and refilling the tree
        void balance();

        //helper method - fills an array with the values of the tree in ascending order
        void fillArrayHelper(TreeNode<T>* subTreeRoot, T* arr);

        //helper method - refills the tree with the values from an ordered array so that the tree becomes balanced
        void fillTreeHelper(TreeNode<T>* subTreeRoot, TreeNode<T>*& parent, T* arr, int low, int high, bool isLeftChild);

        //helper method - removes all nodes from the tree except for the root; used in the rebalancing process
        void clearTree();

        //helper method - recursively searches the tree for a node with the given data
        TreeNode<T>* searchHelper(TreeNode<T>* subTreeRoot, T data);

        //helper method - recursively prints the data in the tree to a file in ascending order
        void printToFileHelper(TreeNode<T>* subTreeRoot);
};

//default constructor
template <typename T>
LazyBST<T>::LazyBST(){
    m_root = NULL;
    m_size = 0;
}

//destructor
template <typename T>
LazyBST<T>::~LazyBST(){
    if(m_root != NULL){
        delete m_root;
    }
}

//accessor for m_size member variable
template <typename T>
int LazyBST<T>::getSize(){
    return m_size;
}

//insert method - creates a new node with the given data and puts it in the correct place in the tree
template <typename T>
void LazyBST<T>::insert(T data){
    TreeNode<T>* newNode = new TreeNode<T>(data);
    insertHelper(m_root, newNode);
    ++m_size;
    checkForBalance();
}

//helper method - recursively finds the right place to insert a new node
template <typename T>
void LazyBST<T>::insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode){
    if(subTreeRoot == NULL){
        subTreeRoot = newNode; //pointer swap
    }else if(newNode->m_data < subTreeRoot->m_data){
        insertHelper(subTreeRoot->m_left, newNode);
    }else if(newNode->m_data > subTreeRoot->m_data){
        insertHelper(subTreeRoot->m_right, newNode);
    }
}

//returns true if the tree contains a node with data that matches the parameter
template <typename T>
bool LazyBST<T>::contains(T data){
    TreeNode<T>* newNode = new TreeNode<T>(data);
    return containsHelper(m_root, newNode);
}

//helper method - recursively determines if a certain piece of data exists in the tree
template <typename T>
bool LazyBST<T>::containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode){
    if(subTreeRoot == NULL){
        return false;
    }else if(newNode->m_data == subTreeRoot->m_data){
        return true;
    }else if(newNode->m_data < subTreeRoot->m_data){
        return containsHelper(subTreeRoot->m_left, newNode);
    }else{
        return containsHelper(subTreeRoot->m_right, newNode);
    }
}

//prints the contents of the tree in ascending order
template <typename T>
void LazyBST<T>::printTreeInOrder(){
    printTreeInOrderHelper(m_root);
}

//helper method - recursively prints the tree's nodes in ascending order
template <typename T>
void LazyBST<T>::printTreeInOrderHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot != NULL){
        printTreeInOrderHelper(subTreeRoot -> m_left);
        std::cout << subTreeRoot->m_data << std::endl;
        printTreeInOrderHelper(subTreeRoot -> m_right);
    }
}

//prints the contents of the tree; children are printed before parents
template <typename T>
void LazyBST<T>::printTreePostOrder(){
    printTreePostOrderHelper(m_root);
}

//helper method - recursively prints the tree's nodes in post-order format
template <typename T>
void LazyBST<T>::printTreePostOrderHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot != NULL){
        printTreePostOrderHelper(subTreeRoot->m_left);
        printTreePostOrderHelper(subTreeRoot->m_right);
        std::cout << subTreeRoot->m_data << std::endl;
    }
}

//returns the data (type T) with the minimum value in the tree
template <typename T>
T LazyBST<T>::getMin(){
    if (m_size == 0){ //if empty
        throw std::out_of_range("Tree is empty. No min value exists.");
    }
    return getMinHelper(m_root);
}

//helpder method - recursively finds the minimum value in the tree
template <typename T>
T LazyBST<T>::getMinHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot->m_left == NULL){
        return subTreeRoot->m_data;
    }else{
        return getMinHelper(subTreeRoot->m_left);
    }
}

//returns the data (type T) with the maximum value in the tree
template <typename T>
T LazyBST<T>::getMax(){
    if (m_size == 0){ //if empty
        throw std::out_of_range("Tree is empty. No max value exists.");
    }
    return getMaxHelper(m_root);
}

//helpder method - recursively finds the maximum value in the tree
template <typename T>
T LazyBST<T>::getMaxHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot->m_right == NULL){
        return subTreeRoot->m_data;
    }else{
        return getMaxHelper(subTreeRoot->m_right);
    }
}

//helper method - used when removing a node
template <typename T>
void LazyBST<T>::findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent){
    while(target != NULL && target->m_data != key){
        parent = target;
        if(key < target->m_data){
            target = target->m_left;
        }else{
            target = target->m_right;
        }
    }
}

//helper method - finds the successor of a node that will be removed
template <typename T>
TreeNode<T>* LazyBST<T>::getSuccessor(TreeNode<T>* rightChild){
    while(rightChild->m_left != NULL){
        rightChild = rightChild->m_left;
    }
    return rightChild;
}

//remove method - finds node with data that matches the parameter and removes it from the tree
template <typename T>
void LazyBST<T>::remove(T d){
    if (m_size == 0){ //if tree is empty, nothing to do
        return;
    }
    TreeNode<T>* target = NULL;
    TreeNode<T>* parent = NULL;
    target = m_root;
    findTarget(d,target, parent);
    if(target == NULL){ //not in the tree, nothing to do
        return;
    }
    if(target->m_left == NULL && target->m_right == NULL){ //no children, it's a leaf
        if(target == m_root){
            m_root = NULL;
        }else{ //it's not the root
            if(target == parent->m_left){
                parent->m_left = NULL;
            }else{
                parent->m_right = NULL;
            }
        }
    }else if(target->m_left != NULL && target->m_right !=NULL){ // 2 child case
        TreeNode<T>* suc = getSuccessor(target->m_right);
        T value = suc->m_data;
        remove(value);
        target->m_data = value;
    }else{ // 1 child case
        TreeNode<T>* child;
        if(target->m_left != NULL){
            child = target->m_left;
        }else{
            child = target->m_right;
        }
        if(target == m_root){
            m_root = child;
        }else{
            if(target == parent->m_left){
                parent->m_left = child;
            }else{
                parent->m_right = child;
            }
        }
    }
    --m_size;
}

//returns the greatest depth of the subtree anchored at the given node
template <typename T>
int LazyBST<T>::getMaxDepth(TreeNode<T>* subTreeRoot){
    if (subTreeRoot == NULL) {
        return 0;
    }
    int leftHeight = getMaxDepth(subTreeRoot->m_left);
    int rightHeight = getMaxDepth(subTreeRoot->m_right);
    if (leftHeight > rightHeight){
        return 1 + leftHeight;
    }
    else {
        return 1 + rightHeight;
    }
}

//checks to see if the tree needs to be rebalanced
template <typename T>
void LazyBST<T>::checkForBalance(){
    double leftHeight = getMaxDepth(m_root->m_left);
    double rightHeight = getMaxDepth(m_root->m_right);
    if (m_size > 2){
        if (m_root->m_left == NULL && rightHeight >= 2){
            balance();
        }
        else if (m_root->m_right == NULL && leftHeight >= 2){
            balance();
        }
        else if ((leftHeight / rightHeight) > 1.5 || (rightHeight / leftHeight > 1.5)){
            balance();
        }
    }
    
}

//rebalances the tree by adding the values to an array and refilling the tree
template <typename T>
void LazyBST<T>::balance(){
    m_orderedArr = new T[m_size];
    m_currIdx = 0;
    fillArrayHelper(m_root, m_orderedArr);
    clearTree();
    m_fillCounter = 0;
    fillTreeHelper(m_root, m_root, m_orderedArr, 0, m_arrSize - 1, false);
    m_size = m_arrSize;
    delete[] m_orderedArr;
}

//helper method - fills an array with the values of the tree in ascending order
template <typename T>
void LazyBST<T>::fillArrayHelper(TreeNode<T>* subTreeRoot, T* arr){
    if(subTreeRoot != NULL){
        fillArrayHelper(subTreeRoot->m_left, arr);
        arr[m_currIdx++] = subTreeRoot->m_data;
        fillArrayHelper(subTreeRoot->m_right, arr);
    }    
}

//helper method - refills the tree with the values from an ordered array so that the tree becomes balanced
template <typename T>
void LazyBST<T>::fillTreeHelper(TreeNode<T>* subTreeRoot, TreeNode<T>*& parent, T* arr, int low, int high, bool isLeftChild){
    if (m_fillCounter < m_arrSize){  //makes sure that not all elements in the array have been used
        if (low > high){ //if this part of the array has been fully searched already
            return;
        }
        int midpoint = low + (high - low) / 2;
        if (subTreeRoot == NULL){    //anything but the root (since the tree has been cleard) --> we have to add a node
            subTreeRoot = new TreeNode<T>(arr[midpoint]);
            if (isLeftChild){
                parent->m_left = subTreeRoot;
            }
            else {
                parent->m_right = subTreeRoot;
            }
            m_fillCounter++;
        }
        else {  //only applies to the root 
            subTreeRoot->m_data = arr[midpoint];
            m_fillCounter++;
        }
        fillTreeHelper(subTreeRoot->m_left, subTreeRoot, arr, low, midpoint - 1, true);
        fillTreeHelper(subTreeRoot->m_right, subTreeRoot, arr, midpoint + 1, high, false);
    }
}

//helper method - removes all nodes from the tree except for the root; used in the rebalancing process
template <typename T>
void LazyBST<T>::clearTree(){
    m_arrSize = m_size;
    for (int i = 0; i < m_arrSize; i++){
        if (m_orderedArr[i] != m_root->m_data){
            remove(m_orderedArr[i]);
        }
    }
}

/*
Search method - searches the tree for a node with the given data
if found, returns a pointer to the node; if not, returns a pointer to NULL
*/
template <typename T>
TreeNode<T>* LazyBST<T>::search(T key){
    return searchHelper(m_root, key);
}

//helper method - recursively searches the tree for a node with the given data
template <typename T>
TreeNode<T>* LazyBST<T>::searchHelper(TreeNode<T>* subTreeRoot,T key){
    if (subTreeRoot == NULL || subTreeRoot->m_data == key){
        return subTreeRoot;
    }
    if (key > subTreeRoot->m_data){
        return searchHelper(subTreeRoot->m_right, key);
    }
    return searchHelper(subTreeRoot->m_left, key);
}

//prints the contents of the tree to a file in ascending order
template <typename T>
void LazyBST<T>::printToFile(std::string fileName){
    m_outFS.open(fileName);
    printToFileHelper(m_root);
    m_outFS.close();
}

//helper method - recursively prints the data in the tree to a file in ascending order
template <typename T>
void LazyBST<T>::printToFileHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot != NULL){
        printToFileHelper(subTreeRoot -> m_left);
        m_outFS << subTreeRoot->m_data << std::endl;
        printToFileHelper(subTreeRoot -> m_right);
    }
}


#endif