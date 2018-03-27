//
//  Tree.hpp
//  DataStructures
//
//  Created by Schimel, Dustin on 3/27/18.
//  Copyright © 2018 Schimel, Dustin. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include "../../Nodes/BinaryTreeNode.hpp"

template <class Type>
class Tree
{
protected:
    BinaryTreeNode<Type> * root;
public:
    //Informational Methods
    virtual int getSize() = 0;
    virtual int getheight() = 0;
    virtual bool isComplete() = 0;
    virtual bool isBalanced() = 0;
    //*Data Methods*
    virtual void insert(Type data) = 0;
    virtual void contains(Type data) = 0;
    virtual void remove(Type data) = 0;
    //*Traversals*
    virtual void inOrderTraversals() = 0;
    virtual void preOrderTraversal() = 0;
    virtual void postOrderTraversal() = 0;
};

#endif /* Tree_hpp */