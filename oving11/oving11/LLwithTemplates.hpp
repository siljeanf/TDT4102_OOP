//
//  LLwithTemplates.hpp
//  oving11
//
//  Created by Silje Anfindsen on 26/03/2019.
//  Copyright © 2019 Silje Anfindsen. All rights reserved.
//

#ifndef LLwithTemplates_hpp
#define LLwithTemplates_hpp

#include <stdio.h>
#pragma once

#include <memory>
#include <ostream>
#include <string>
#include "iteratorer.hpp"

using namespace std;


void testLinkedList();

namespace LinkedList {
    
    template<template T>
    class Node {
    private:
        const T value;    // The data held by the LinkedList
        std::unique_ptr<Node> next; // unique_ptr to the next node
        Node<T>* prev;                 // raw (non-owning) ptr to the previous node
        
    public:
        Node<T>() : value(), next(nullptr), prev(nullptr) {}
        
        // construct a node with string value, a unique_ptr to the next node, and a pointer to the previous node
        Node<T>(const std::T& value, std::unique_ptr<Node> next, Node<T>* prev)
        : value(value), next(std::move(next)), prev(prev){}
        
        // We can use the default destructor, since unique_ptr takes care of deleting memory
        ~Node<T>() = default;
        
        // return the value of the node
        T getValue() const
        { return value; }
        
        // return a raw (non-owning) pointer to the next node
        Node<T>* getNext() const
        { return next.get(); }
        
        // return a raw (non-owning) pointer to the previous node
        Node<T>* getPrev() const
        { return prev; }
        
        // write the value of the node to the ostream
        friend ostream & operator<<(std::ostream & os, const Node<T> & node){
            os << node.getValue() << endl;
            return os;
        }
    
        friend class LinkedList;
};
    
    template<typename T>
    class LinkedList {
    private:
        // ptr to the first node
        std::unique_ptr<Node<T>> head;
        
        // a raw pointer to the last node, the last node is always a dummy node
        // this is declared as a const ptr to a Node, so that tail never can
        // point anywhere else
        Node<T>* const tail;
        
    public:
        //create the dummy node, and make tail point to it
        LinkedList(): head( std::make_unique<Node<T>() ), tail( head.get() ) {}
        
        ~LinkedList() = default;
        
        //if next is a nullptr (i.e. head is the dummy node), the list is emtpy
        bool isEmpty() const
        { return !head->next; }
        
        //return a pointer to first element
        Node* begin() const
        { return head.get(); }
        
        //return a pointer to beyond-end element
        Node* end() const
        { return tail; }
        
        // The insert function takes a pointer to node (pos) and a string (value). It creates a new
        // node which contains value. The new node is inserted into the LinkedList BEFORE the
        // node pointed to by pos.
       
        Node<T> * insert(Node<T> *pos, const std::T& value){
        
            auto newNode= make_unique<Node<T>>(value,move( pos->prev->next), pos->prev);
            
            pos->prev = newNode.get();
            
            pos->prev->next = move(newNode);
            
            return pos->prev;
        }
        
        // The find function traverses the linked list and returns a pointer to the first node
        // that contains the value given.
        // If the value isn't in the list, find returns a pointer to the dummy node at the end
        // of the list.
        Node* find(const std::T& value) {
            
                auto newPos = pos->next.get();
                newPos->prev = pos->prev;
                
                pos->prev->next = move(pos->next);
                
                return newPos;
            }
        }
        
        // The remove function takes a pointer to a node, and removes the node from the list. The
        // function returns a pointer to the element after the removed node.
        Node* remove(Node<T>* pos){
            Node<T> *p = head.get();
        
            while (p->getValue() != value and p != end()){
                p = p->getNext();
            
            }
            return p;
    }
        
        // The remove function takes a string and removes the first node which contains the value.
        void remove(const T& value) {
            Node<T> *p = find(value);
            if (p!=end() ) { //sjekker at funksjonen ikke er lik dummy node
                remove(p);
        }
    }
        
        // write a string representation of the list to the ostream
        friend ostream& operator<<(std::ostream& os, const LinkedList& ll) {
            Node<T> *p = ll.begin();
            while (p != ll.end() ) { //itererer gjennom linkedlist
                os << *p << " ";
            }
            os << endl;
            //må gå gjennom linkedlist og skrive hver verdi til os
            return os;
    }
    };
    
}// namespace LinkedList




#endif /* LLwithTemplates_hpp */
