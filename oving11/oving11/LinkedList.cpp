//
//  LinkedList.cpp
//  oving11
//
//  Created by Silje Anfindsen on 25/03/2019.
//  Copyright © 2019 Silje Anfindsen. All rights reserved.
//

#include "LinkedList.hpp"
namespace LinkedList {
 
void testLinkedList(){
    
}
    
    
// write the value of the node to the ostream
std::ostream& operator<<(std::ostream & os, const Node & node){
    os << node.getValue() << endl;
    return os;
}

//legger til en en peker til en ny node (med verdien value)
//den nye noden skal settes inn i den lenkede listen før noden som er pekt på av pos!

Node* LinkedList::insert(Node* pos, const std::string& value) {
    //må huske å først flytte uniqeptr til nytt element før jeg flytter uniqueptr til gammelt element (pos)
    
    //oppretter en ny uniqueptr til value og endrer noden pos peker på
    auto newNode= make_unique<Node>(value,move( pos->prev->next), pos->prev);
    
    pos->prev = newNode.get();
    
    pos->prev->next = move(newNode);
    
    return pos->prev;
}

//fjerner noden fra listen og returnerer en peker til elementet etter å ha fjernet noden
Node* LinkedList::remove(Node* pos){
    //fjerner pos ved å gi dens prevs uniqueptr en ny pos
    //henter pekeren til den pekeren vi har fjerna
    auto newPos = pos->next.get();
    newPos->prev = pos->prev;
    
    pos->prev->next = move(pos->next);
    
    return newPos;
}
    
    
//går gjennom den lenkede listen og returner en peker til første node som inneholder verdien "value""
//hvis verdien ikke finnes,returnerer den en peker til dummy node i slutten av listen
Node* LinkedList::find(const std::string& value){
    Node *p = head.get();

    while (p->getValue() != value and p != end()){
        p = p->getNext();
        
    }
    return p;
}
    
// The remove function takes a string and removes the first node which contains the value.
    void LinkedList::remove(const std::string& value) {
        Node *p = find(value);
        if (p!=end() ) { //sjekker at funksjonen ikke er lik dummy node
            remove(p);
        }
    }
// write a string representation of the list to the ostream
std::ostream& operator<<(std::ostream& os, const LinkedList& ll) {
    Node *p = ll.begin();
    while (p != ll.end() ) { //itererer gjennom linkedlist
        os << *p << " ";
    }
    os << endl;
    //må gå gjennom linkedlist og skrive hver verdi til os
    return os;
}
    
}//end namespace
