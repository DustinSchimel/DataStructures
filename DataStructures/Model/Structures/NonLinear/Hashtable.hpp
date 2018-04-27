//
//  Hashtable.hpp
//  DataStructures
//
//  Created by Schimel, Dustin on 4/27/18.
//  Copyright © 2018 Schimel, Dustin. All rights reserved.
//

#ifndef Hashtable_hpp
#define Hashtable_hpp

#include "../Nodes/HashNode.hpp"

template <class Type>
class Hashtable
{
private:
    HashNode<Type> ** internalStorage;
    long size;
    long capacity;
    double loadFactor;
    
    long getNextPrime();
    bool isPrime(long current);
    void resize();
    long findPosition(HashNode<Type> * insertedNode);
    long handleCollision(HashNode<Type> * insertedNode, long index);
    
public:
    Hashtable();
    ~Hashtable();
    
    void insert(Type data);
    long getSize();
};

template <class Type>
Hashtable<Type> :: Hashtable()
{
    
}

template <class Type>
Hashtable<Type> :: ~Hashtable()
{
    
}

template <class Type>
Hashtable<Type> :: isPrime(long current)
{
    
}

#endif /* Hashtable_hpp */
