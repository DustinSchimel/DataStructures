//
//  AVLTreeTester.hpp
//  DataStructures
//
//  Created by Schimel, Dustin on 4/17/18.
//  Copyright © 2018 Schimel, Dustin. All rights reserved.
//

#ifndef AVLTreeTester_hpp
#define AVLTreeTester_hpp

#include "../Model/Nodes/BinaryTreeNode.hpp"
#include "../Model/Structures/NonLinear/AVLTree.hpp"
#include <iostream>

class AVLTreeTester
{
private:
    BinaryTreeNode<int> testNode;
    AVLTree<int> testIntTree;
    AVLTree<string> testStringTree;
public:
    void doAVLTreeStuff();
};

#endif /* AVLTreeTester_hpp */

