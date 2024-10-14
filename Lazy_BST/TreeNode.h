/*
Alex Cannizzaro
alexcannizzaro16@gmail.com
Course: CPSC-350-01 (Data Structures and Algorithms)
Programming Assignment 5: Lazy BST
Header file for the TreeNode class - contains function declarations and definitions
*/
#ifndef TREENODE_H
#define TREENODE_H

#include <cstdlib>

//TreeNode class - objects represent nodes of a tree
template <typename T>
class TreeNode{
    public:
        //constructor with parameter representing the data stored in the node
        TreeNode(T data);
        //destructor
        virtual ~TreeNode();
        //accessor for m_data member variable
        T getData();
    template <typename S>
    friend class LazyBST;
        T m_data;  //the data stored in the node
        TreeNode<T>* m_left;  //the node's left child
        TreeNode<T>* m_right; //the node's right child
};

//constructor with parameter representing the data stored in the node
template <typename T>
TreeNode<T>::TreeNode(T data){
    m_data = data;
    m_left = NULL;
    m_right = NULL;
}

//destructor
template <typename T>
TreeNode<T>::~TreeNode(){
    if(m_left != NULL){
    delete m_left;
    }
    if(m_right != NULL){
    delete m_right;
    }
}

//accessor for m_data member variable
template <typename T>
T TreeNode<T>::getData(){
    return m_data;
}

#endif
