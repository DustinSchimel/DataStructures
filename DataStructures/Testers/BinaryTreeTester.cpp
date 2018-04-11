//
//  BinaryTreeTester.cpp
//  DataStructures
//
//  Created by Schimel, Dustin on 3/27/18.
//  Copyright © 2018 Schimel, Dustin. All rights reserved.
//

#include "BinaryTreeTester.hpp"

void BinaryTreeTester :: doTreeStuff()
{
    testIntTree.insert(3);
    testIntTree.insert(1);
    testIntTree.insert(2);
    testIntTree.insert(-3246000);
    testIntTree.insert(-12);
    testIntTree.insert(7);
    testIntTree.insert(5);
    testIntTree.insert(6);
    testIntTree.insert(8);
    testIntTree.insert(5000);
    testIntTree.insert(9001);
    testIntTree.insert(10);
    testIntTree.insert(600);
    
    testStringTree.insert(" I ");
    testStringTree.insert(" Don't ");
    testStringTree.insert(" Know ");
    testStringTree.insert(" What ");
    testStringTree.insert(" I'm ");
    testStringTree.insert(" Doing ");
    testStringTree.insert(" Right ");
    testStringTree.insert(" Now ");
    testStringTree.insert(" At ");
    testStringTree.insert(" This ");
    testStringTree.insert(" Very ");
    testStringTree.insert(" Momemt ");
    
    
    testIntTree.inOrderTraversal();
    testStringTree.inOrderTraversal();
}
