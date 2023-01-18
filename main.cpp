//
//  main.cpp
//  hw3
//
//  Created by Kaytlin Simmer on 2/29/20.
//  Copyright © 2020 Kaytlin Simmer. All rights reserved.
//

//headers
#include <string>
#include <iostream>
#include <fstream>
//#include "ArgumentManager.h"

using namespace std;

//Node class
template <class itemType>
class Node
{
private:
    itemType item;
    Node<itemType>* next;
public:
    Node()
    {
        next = nullptr;
    }
    Node(const itemType& anItem)
    {
        item = anItem;
    }
    Node(const itemType& anItem, Node<itemType>* nextNodeptr)
    {
        item = anItem;
        next = nextNodeptr;
    }
    void setItem(const itemType& anItem)
    {
        item = anItem;
    }
    void setNext(Node <itemType>* nextNodePtr)
    {
        next = nextNodePtr;
    }
    itemType getItem() const
    {
        return item;
    }
    Node<itemType>* getNext() const
    {
        return next;
    }
    
};

//Linked Stack class
template <class itemType>
class linkedStack
{
private:
    Node<itemType>* topPtr;
public:
    linkedStack()
    {
        topPtr = nullptr;
    }
    
    linkedStack(const linkedStack<itemType>& aStack)
    {
        Node <itemType>* origChainPtr = aStack -> topPtr;
        if (origChainPtr == nullptr)
            topPtr = nullptr;
        else
        {
            topPtr = new Node<itemType>();
            topPtr -> setIteam(origChainPtr->getItem());
            Node <itemType>* newChainPtr = topPtr;
            while (origChainPtr != nullptr)
            {
                origChainPtr = origChainPtr -> getNext();
                itemType nextItem = origChainPtr->getItem();
                Node <itemType>* newNodePtr = new Node<itemType>(nextItem);
                newChainPtr -> setNext(newNodePtr);
                newChainPtr = newChainPtr -> getNext();
            }
            newChainPtr->setNext(nullptr);
        }
    }
    
    ~linkedStack()
    {
        while (!isEmpty())
            pop();
    }
    
    bool isEmpty() const
    {
        return topPtr == nullptr;
    }
    
    bool push(const itemType& newItem)
    {
        Node <itemType>* newNodePtr = new Node <itemType> (newItem, topPtr);
        topPtr = newNodePtr;
        newNodePtr = nullptr;
        return true;
    }
    
    bool pop()
    {
        bool result = false;
        if (!isEmpty())
        {
            Node <itemType>* nodeToDeletePtr = topPtr;
            topPtr = topPtr -> getNext();
            nodeToDeletePtr -> setNext(nullptr);
            delete nodeToDeletePtr;
            nodeToDeletePtr = nullptr;
            result = true;
        }
        return result;
    }
    
    itemType peek() const
    {
        assert (!isEmpty());
        return topPtr -> getItem();
    }
    
};

int main(int argc, char * argv[])
{
   // ArgumentManager am(argc, argv);
   // string inputN = am.get("input");
  //  string outputN = am.get("output");
 
    ifstream input;
    
    
    int dimension;
    
    string inputN;
    
    input.open(inputN);
    input>>dimension;
  
}
