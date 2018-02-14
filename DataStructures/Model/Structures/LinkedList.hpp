//
//  LinkedList.hpp
//  DataStructures
//
//  Created by Schimel, Dustin on 2/14/18.
//  Copyright © 2018 Schimel, Dustin. All rights reserved.
//

#include "List.hpp"

using namespace std: //Used for keyword access. Use this to make sure your pointers are pointing to the right things

#ifndef LinkedList_hpp  //May have to move these up
#define LinkedList_hpp

template <class Type>
class LinkedList : public List<Type>
{
protected:
    
    LinearNode<Type> * front;
    LinearNode<Type> * end;
    
public:
    //Constructors
    LinkedList();
    //Destructor
    virtual ~LinkedList();  //Virtual so it can be overridden.
    //Helper methods
    int getSize() const;
    LinearNode<Type> * getFront();
    LinearNode<Type> * getEnd();
    
    //Structure Methods
    void add(Type item);
    void addAtIndex(int index, Type item);
    Type getFromIndex(int index);
    Type remove(int index);
//      Type setAtIndex(int index, Type item);
//      bool contains(Type item);
}

LinkedList<Type> :: LinkedList()
{
    this->front = nullptr;
    this->end = nullptr;
    this->size = 0;
}

LinkedList<Type> :: ~LinkedList()
{
    LinearNode<Type> * destroyStructure = front;
    while (front != nullptr)
    {
        front = destoryStructure->getNextNode();
        delete destoryStructure;
        destoryStructure = front;
    }
}

void LinkedList<Type> :: add(Type item)
{
    LinearNode<Type> * newData = new LinearNode<Type>(item);
    
    if (this->size == 0)
    {
        this->front = newData;
    }
    else
    {
        this->end->setNextNode(newData);
    }
    
    this-> end = newData;
    
    this->size += 1;
}

#endif /* LinkedList_hpp */
