//
//  Controller.cpp
//  DataStructures
//
//  Created by Schimel, Dustin on 1/31/18.
//  Copyright © 2018 Schimel, Dustin. All rights reserved.
//

#include "Controller.hpp"

using namespace std;

void Controller :: start()
{
    GraphTester puzzle;
    puzzle.testGraph();
    
    //BinaryTreeTester test;
    //test.doTreeStuff();
}

void Controller :: testArray()
{
    Array<int>dustinArray(45);
    
    cout << dustinArray.getSize() << endl;
    
    dustinArray[0] = 123;
    dustinArray.setAtIndex(0, 321);
    
    cout << dustinArray[0] << endl;
}
