//
//  BinarySearchTree.hpp
//  DataStructures
//
//  Created by Schimel, Dustin on 3/29/18.
//  Copyright © 2018 Schimel, Dustin. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include "Tree.hpp"
#include <iostream>

using namespace std;

template <class Type>
class BinarySearchTree : public Tree<Type>
{
protected:
    
    int calculateSize(BinaryTreeNode<Type> * startNode);
    int calculateHeight(BinaryTreeNode<Type> * startNode);
    bool isBalanced(BinaryTreeNode<Type> * startNode);
    bool isComplete(BinaryTreeNode<Type> * startNode, int index, int size);
    
    void inOrderTraversal(BinaryTreeNode<Type> * isStart);
    void preOrderTraversal(BinaryTreeNode<Type> * preStart);
    void postOrderTraversal(BinaryTreeNode<Type> * postStart);
    
    void destroyTree(BinaryTreeNode<Type> * node);
    
    BinaryTreeNode<Type> * getRightMostChild(BinaryTreeNode<Type> * current);
    BinaryTreeNode<Type> * getLeftMostChild(BinaryTreeNode<Type> * current);
    
    void removeNode(BinaryTreeNode<Type> * removeMe);
    
public:
    
    BinarySearchTree();
    ~BinarySearchTree();
    
    BinaryTreeNode<Type> * getRoot();
    
    void setRoot(BinaryTreeNode<Type> * root);
    
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    void demoTraversalSteps(BinaryTreeNode<Type> * node);
    
    int getSize();
    int getHeight();
    bool isComplete();
    bool isBalanced();
    
    bool contains(Type value);
    void insert(Type itemToInsert);
    void remove(Type value);
    
    Type findMinimum();
    Type findMaximum();
};

template <class Type>
BinarySearchTree<Type> :: BinarySearchTree()
{
    this->root = nullptr;
}

//template <class Type>
//~BinarySearchTree<Type> :: BinarySearchTree()
//{
//
//}

template <class Type>
int BinarySearchTree<Type> :: getHeight()
{
    return calculateHeight(this->root);
}

template <class Type>
int BinarySearchTree<Type> :: getSize()
{
    int size = 0;
    
    size += calculateSize(this->root);
    
    return size;
}

template <class Type>
bool BinarySearchTree<Type> :: isComplete()
{
    int index = 0;
    int size = getSize();
    
    return isComplete(this->root, index, size);
}

template <class Type>
bool BinarySearchTree<Type> :: isBalanced()
{
    return false;
}

template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal()
{
    inOrderTraversal(this->root);
}

/*
 In order traversal goes in the order Left, Root, Right
 Notice that the non-recursive case does NOTHING
 */
template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal(BinaryTreeNode<Type> * isStart)
{
    if (isStart != nullptr)
    {
        inOrderTraversal(isStart->getLeftNode());
        cout << isStart->getData() << endl;
        inOrderTraversal(isStart->getRightNode());
    }
}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal()
{
    preOrderTraversal(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal(BinaryTreeNode<Type> * preStart)
{
    
}

template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal()
{
    postOrderTraversal(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal(BinaryTreeNode<Type> * postStart)
{
    
}

template <class Type>
void BinarySearchTree<Type> :: insert(Type itemToInsert)
{
    BinaryTreeNode<Type> * insertMe = new BinaryTreeNode<Type>(itemToInsert);
    BinaryTreeNode<Type> * previous = nullptr;
    BinaryTreeNode<Type> * current = this->root;
    
    if (current == nullptr)
    {
        this->root = insertMe;

    }
    else
    {
        while (current != nullptr)
        {
            previous = current;
            if (itemToInsert < current->getData())
            {
                current = current->getLeftNode();
            }
            else if (itemToInsert > current->getData())
            {
                
                current = current->getRightNode();
            }
            else    //Remove cerr after verification of understanding
            {
                cerr << "Item exists already - Exiting insert" << endl;
                delete insertMe;
                return; //Okay because it is returning NOTHING
            }
        }
        
        if (previous->getData() > itemToInsert)
        {
            previous->setLeftNode(insertMe);
        }
        else
        {
            previous->setRightNode(insertMe);
        }
        insertMe->setRootNode(previous);
    }
}

template <class Type>
bool BinarySearchTree<Type> :: contains(Type value)
{
    return false;
}

template <class Type>
void BinarySearchTree<Type> :: remove(Type value)
{
    
}
        
template <class Type>
int BinarySearchTree<Type> :: calculateSize(BinaryTreeNode<Type> * current)
{
    if(current != nullptr)
    {
        return calculateSize(current->getLeftNode()) + calculateSize(current->getRightNode()) + 1;
    }
    
    return 0;
}

template <class Type>
int BinarySearchTree<Type> :: calculateHeight(BinaryTreeNode<Type> * current)
{
    if (current != nullptr)
    {
        return max(calculateHeight(current->getLeftNode()), calculateHeight(current->getRightNode())) + 1;
    }
}

template <class Type>
bool BinarySearchTree<Type> :: isBalanced(BinaryTreeNode<Type> * current)
{
    int leftHeight = 0;
    int rightHeight = 0;
    
    if(current == nullptr)
    {
        return true;
    }
    
    leftHeight = calculateHeight(current->getLeftNode());
    rightHeight = calculateHeight(current->getRightNode());
    
    int heightDifference = abs(leftHeight - rightHeight);
    bool leftBalanced = isBalanced(current->getLeftNode());
    bool rightBalanced = isBlanced(current->getRightNode());
    
    if (heightDifference <= 1 && leftBalanced && rightBalanced)
    {
        return true;
    }
    return false;
}

template <class Type>
bool BinarySearchTree<Type> :: isComplete(BinaryTreeNode<Type> * startNode, int index, int size)
{
    if(startNode == nullptr)
    {
        return true;
    }
    
    
    if(index >= size)
    {
        return false;
    }
    
    return (isComplete(startNode->getLeftNode(), 2 * index + 1, size) && isComplete(startNode->getRightNode(), 2 * index + 2, size));
}

//template <class Type>
//void BinarySearchTree<Type> :: demo()
//{
//    demoTraversalSteps(this->root);
//}

template <class Type>
void BinarySearchTree<Type> :: demoTraversalSteps(BinaryTreeNode<Type> * start)
{
    if (start != nullptr)
    {
        cout << "Check if left is here" << endl;
        demoTraversalSteps(start->getLeftNode());
        cout << "return to root" << endl;
        cout << "check if right is here" << endl;
        demoTraversalSteps(start->getRightNode());
    }
    else
    {
        cout << "reached nullptr - if on right it's back up the recursive call stack left is go to root" << endl;
    }
}

template <class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getRightMostChild(BinaryTreeNode<Type> * current)
{
    return nullptr;
}

template <class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getLeftMostChild(BinaryTreeNode<Type> * current)
{
    return nullptr;
}

template <class Type>
void BinarySearchTree<Type> :: removeNode(BinaryTreeNode<Type> * removeMe)
{
    
}

template <class Type>
Type BinarySearchTree<Type> :: findMinimum()
{
    return nullptr;
}

template <class Type>
Type BinarySearchTree<Type> :: findMaximum()
{
    return nullptr;
}

template <class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getRoot()
{
    return nullptr;
}

template <class Type>
void BinarySearchTree<Type> :: setRoot(BinaryTreeNode<Type> * root)
{

}

#endif /* BinarySearchTree_hpp */
